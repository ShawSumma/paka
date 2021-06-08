module purr.ir.walk;

import core.memory;
import std.conv;
import purr.io;
import std.string;
import std.algorithm;
import std.ascii;
import purr.ast.ast;
import purr.srcloc;
import purr.vm.bytecode;
import purr.ir.repr;
import purr.ir.bytecode;
import purr.ir.opt;
import purr.type.repr;

__gshared bool dumpast = false;

struct Todo
{
    BasicBlock lambda;
    Node[] args;
    string[] argNames;
    Type[string] locals;
    Func functy;
}

final class Walker
{
    Span[] nodes = [Span.init];
    BasicBlock block;
    BasicBlock funcblk;
    Func curFunc;
    Type[string][] localTypes = [];
    Value[string][] localDefs = [];
    Todo[][] todos = [];

    BasicBlock walkBasicBlock(Node node)
    {
        if (dumpast)
        {
            writeln(node);
            writeln;
        }
        BasicBlock entry = new BasicBlock;
        block = entry;
        funcblk = block;
        walk(node);
        return entry;
    }

    Bytecode walkProgram(Node node)
    {
        localTypes.length++;
        localDefs.length++;
        todos.length++;
        scope (exit)
        {
            localTypes.length--;
            localDefs.length--;
            todos.length--;
        }
        curFunc = Func.empty;
        if (dumpast)
        {
            writeln(node);
            writeln;
        }
        BasicBlock entry = new BasicBlock;
        block = entry;
        funcblk = block;
        Type ret = walk(node);
        if (block.exit is null)
        {
            emit(new PopInstruction(ret));
            emitDefault(new ReturnBranch(Type.nil));
        }
        foreach (nextTodo; todos[$ - 1])
        {
            runTodo(nextTodo);
        }
        Bytecode func = Bytecode.empty;
        BytecodeEmitter emitter = new BytecodeEmitter;
        emitter.emitInFunc(func, entry);
        return func;
    }

    Type walk(Node node)
    {
        if (node.span != Span.init)
        {
            nodes ~= node.span;
        }
        scope (exit)
        {
            if (node.span != Span.init)
            {
                nodes.length--;
            }
        }
        switch (node.id)
        {
        case NodeKind.call:
            return walkExact(cast(Form) node);
        case NodeKind.ident:
            return walkExact(cast(Ident) node);
        case NodeKind.value:
            return walkExact(cast(Value) node);
        default:
            assert(false);
        }
    }

    bool inspecting = false;

    void emit(Instruction instr)
    {
        instr.span = nodes[$ - 1];
        block.instrs ~= instr;
    }

    void emitDefault(Branch branch)
    {
        if (block.exit is null)
        {
            branch.span = nodes[$ - 1];
            block.exit = branch;
        }
    }

    void emit(Branch branch)
    {
        assert(block.exit is null);
        branch.span = nodes[$ - 1];
        block.exit = branch;
    }

    Type walkExact(Ident id)
    {
        string ident = id.repr;
        if (ident.isNumeric)
        {
            assert(false);
        }
        else
        {
            Type[string] locals = localTypes[$ - 1];
            if (Type* ret = ident in locals)
            {
                emit(new LoadInstruction(ident, *ret));
                return *ret;
            }
            foreach_reverse (Type[string] level; localTypes[0 .. $ - 1])
            {
                if (Type* ret = ident in level)
                {
                    Type ty = *ret;
                    if (Func func = ty.as!Func)
                    {
                        emit(new PushInstruction(func.impl, ty));
                        return ty;
                    }
                }
            }
            throw new Exception("undefined variable: " ~ ident);
        }
    }

    Type walkIf(Node[] args)
    {
        BasicBlock iftrue = new BasicBlock;
        BasicBlock iffalse = new BasicBlock;
        BasicBlock after = new BasicBlock;
        walk(args[0]);
        emit(new LogicalBranch(iftrue, iffalse));
        block = iftrue;
        Type br1 = walk(args[1]);
        emitDefault(new GotoBranch(after));
        block = iffalse;
        Type br2 = walk(args[2]);
        emitDefault(new GotoBranch(after));
        block = after;
        if (br1.isUnk)
        {
            (cast(Unk) br1).set(br2);
        }
        else if (br2.isUnk)
        {
            (cast(Unk) br2).set(br1);
        }
        if (!br1.fits(br2))
        {
            throw new Exception("arms of if of different types");
        }
        return br1;
    }

    Type walkAnd(Node[] args)
    {
        BasicBlock iftrue = new BasicBlock;
        BasicBlock iffalse = new BasicBlock;
        BasicBlock after = new BasicBlock;
        walk(args[0]);
        emit(new LogicalBranch(iftrue, iffalse));
        block = iftrue;
        walk(args[1]);
        emitDefault(new GotoBranch(after));
        block = iffalse;
        emit(new PushInstruction(false, Type.logical));
        emitDefault(new GotoBranch(after));
        block = after;
        return Type.logical;
    }

    Type walkOr(Node[] args)
    {
        BasicBlock iftrue = new BasicBlock;
        BasicBlock iffalse = new BasicBlock;
        BasicBlock after = new BasicBlock;
        walk(args[0]);
        emit(new LogicalBranch(iftrue, iffalse));
        block = iftrue;
        emit(new PushInstruction(true, Type.logical));
        emitDefault(new GotoBranch(after));
        block = iffalse;
        walk(args[1]);
        emitDefault(new GotoBranch(after));
        block = after;
        return Type.logical;
    }

    Type walkWhile(Node[] args)
    {
        BasicBlock cond = new BasicBlock;
        BasicBlock iftrue = new BasicBlock;
        BasicBlock after = new BasicBlock;
        emitDefault(new GotoBranch(cond));
        block = cond;
        walk(args[0]);
        emitDefault(new LogicalBranch(iftrue, after));
        block = iftrue;
        Type blk = walk(args[1]);
        emit(new PopInstruction(blk));
        emitDefault(new GotoBranch(cond));
        block = after;
        return Type.nil;
    }

    Type walkDo(Node[] args)
    {
        if (args.length == 0)
        {
            return Type.nil;
        }
        else
        {
            foreach (arg; args[0 .. $ - 1])
            {
                Type got = walk(arg);
                emit(new PopInstruction(got));
            }
            return walk(args[$ - 1]);
        }
    }

    Type walkStoreFun(Node lhs, Node[] args, Node rhs)
    {
        Node funForm = new Form("fun", [new Form("args", args), rhs]);
        Node setForm = new Form("set", lhs, funForm);
        return walk(setForm);
    }

    Type walkStore(Node[] args)
    {
        if (Ident id = cast(Ident) args[0])
        {
            Type ty = walk(args[1]);
            emit(new StoreInstruction(id.repr, ty));
            localTypes[$ - 1][id.repr] = ty;
            return ty;
        }
        else if (Form call = cast(Form) args[0])
        {
            if (call.form == "args" || call.form == "call")
            {
                return walkStoreFun(call.args[0], call.args[1 .. $], args[1]);
            }
            else
            {
                assert(false, call.form);
            }
        }
        else
        {
            assert(false);
        }
    }

    Type walkType(Node node)
    {
        switch (node.id)
        {
        case NodeKind.call:
            Form form = cast(Form) node;
            assert(false);
        case NodeKind.ident:
            Ident id = cast(Ident) node;
            switch (id.repr)
            {
            default:
                foreach (layer; localTypes)
                {
                    if (Type* ptr = id.repr in layer)
                    {
                        return *ptr;
                    }
                }
                throw new Exception("type not found " ~ id.repr);
            case "Frame":
                return Type.frame;
            case "Int":
                return Type.integer;
            case "Float":
                return Type.number;
            }
            break;
        case NodeKind.value:
            throw new Exception("type cannot be a literal value");
        default:
            assert(false);
        }
    }

    void runTodo(Todo todo)
    {
        BasicBlock last = block;
        todos.length++;
        localTypes ~= todo.locals;
        curFunc = todo.functy;
        scope (exit)
        {
            block = last;
            todos.length--;
            localTypes.length--;
        }
        block = todo.lambda;
        Type ret = Type.nil;
        foreach (i, v; todo.args[1 .. $])
        {
            ret = walk(v);
        }
        if (block.exit is null)
        {
            emitReturn(ret);
        }
        foreach (nextTodo; todos[$ - 1])
        {
            runTodo(nextTodo);
        }
    }

    Type walkFun(Node[] args)
    {
        Form argl = cast(Form) args[0];
        Type[string] locals;
        string[] argNames;
        Type[] argTypes;
        foreach (i, v; argl.args)
        {
            if (Form form = cast(Form) v)
            {
                if (form.form != "::")
                {
                    throw new Exception("args type must start with a `::`");
                }
                else
                {
                    Ident name = cast(Ident) form.args[0];
                    Type type = walkType(form.args[1]);
                    locals[name.repr] = type;
                    argNames ~= name.repr;
                    argTypes ~= type;
                }
            }
            if (Ident name = cast(Ident) v)
            {
                Type type = Type.unk;
                locals[name.repr] = type;
                argNames ~= name.repr;
                argTypes ~= type;
            }
        }
        BasicBlock lambda = new BasicBlock;
        Func functy = Func.empty;
        functy.args = argTypes;
        emit(new LambdaInstruction(lambda, argNames, locals, functy.impl));
        todos[$ - 1] ~= Todo(lambda, args, argNames, locals, functy);
        return cast(Type) functy;
    }

    void emitReturn(Type ret)
    {
        // if (curFunc.ret.isUnk && ret.as!Never !is null)
        if (curFunc.ret.isUnk)
        {
            (cast(Unk) curFunc.ret).set(ret);
        }
        else if (ret.isUnk)
        {
            (cast(Unk) ret).set(curFunc.ret);
        }
        else
        {
            assert(curFunc.ret.fits(ret), curFunc.ret.to!string ~ " vs " ~ ret.to!string);
        }
        emit(new ReturnBranch(ret));
    }

    Type walkReturn(Node[] args)
    {
        if (args.length == 0)
        {
            assert(false);
        }
        Type ret = walk(args[0]);
        return Type.never;
    }

    alias walkIndex = walkBinary!"index";

    Type walkBinary(string op)(Node[] args)
    {
        Type t1 = walk(args[0]);
        Type t2 = walk(args[1]);
        emit(new OperatorInstruction(op, t1, [t1, t2]));
        return t1;
    }

    Type walkUnary(string op)(Node[] args)
    {
        Type t1 = walk(args[0]);
        emit(new OperatorInstruction(op, t1, [t1]));
        return t1;
    }

    Type walkCall(Node fun, Node[] args)
    {
        Func func = walk(fun).as!Func;
        if (func is null)
        {
            throw new Exception("type is not a function");
        }
        if (func.args.length != args.length)
        {
            throw new Exception("wrong number of arguments");
        }
        foreach (index, arg; args)
        {
            Type wantty = func.args[index];
            Type gotty = walk(arg);
            if (wantty.isUnk)
            {
                (cast(Unk) wantty).set(gotty);
            }
            else if (gotty.isUnk)
            {
                (cast(Unk) gotty).set(wantty);
            }
            else if (!gotty.fits(wantty))
            {
                throw new Exception("expected " ~ wantty.to!string ~ " got " ~ gotty.to!string);
            }
        }
        emit(new CallInstruction(func.args));
        return func.ret;
    }

    Type walkRec(Node[] args)
    {
        int size;
        foreach (arg; args)
        {
            Type argty = walk(arg);
            size += argty.size;
        }
        emit(new RecInstruction(size));
        return curFunc.ret;
    }

    Type walkPrint(Node[] args)
    {
        assert(args.length == 1);
        Type t1 = walk(args[0]);
        emit(new PrintInstruction(t1));
        return Type.nil;
    }

    // Type walkLabel(Node[] args)
    // {
    //     BasicBlock after = new BasicBlock;
    //     emitDefault(new LabelBranch(after));
    //     block = after;
    //     return Type.frame;
    // }

    // Type walkJump(Node[] args)
    // {
    //     walk(args[0]);
    //     BasicBlock after = new BasicBlock;
    //     emitDefault(new JumpBranch);
    //     block = after;
    //     return Type.nil;
    // }

    Type walkSpecialForm(string special, Node[] args)
    {
        switch (special)
        {
        default:
            assert(0, "not implemented: " ~ special);
        case "do":
            return walkDo(args);
        case "if":
            return walkIf(args);
        case "while":
            return walkWhile(args);
        case "&&":
            return walkAnd(args);
        case "||":
            return walkOr(args);
        case "set":
            return walkStore(args);
        case "fun":
            return walkFun(args);
        case "rcall":
            return walkCall(args[$ - 1], args[0 .. $ - 1]);
        case "rec":
            return walkRec(args);
        case "print":
            return walkPrint(args);
        case "call":
            return walkCall(args[0], args[1 .. $]);
        case "return":
            throw new Exception("return is broken");
            // return walkReturn(args);
        case "index":
            return walkIndex(args);
        case "+":
            return walkBinary!"add"(args);
        case "%":
            return walkBinary!"mod"(args);
        case "not":
            return walkUnary!"not"(args);
        case "-":
            if (args.length == 1)
            {
                return walkUnary!"neg"(args);
            }
            else
            {
                return walkBinary!"sub"(args);
            }
        case "*":
            return walkBinary!"mul"(args);
        case "/":
            return walkBinary!"div"(args);
        case "<":
            return walkBinary!"lt"(args);
        case ">":
            return walkBinary!"gt"(args);
        case "<=":
            return walkBinary!"lte"(args);
        case ">=":
            return walkBinary!"gte"(args);
        case "!=":
            return walkBinary!"neq"(args);
        case "==":
            return walkBinary!"eq"(args);
        }
    }

    Type walkExact(Form call)
    {
        return walkSpecialForm(call.form, call.args);
    }

    Type walkExact(Value val)
    {
        emit(new PushInstruction(val.value, val.type));
        return val.type;
    }
}

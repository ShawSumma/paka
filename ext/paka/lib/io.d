module paka.lib.io;

import purr.dynamic;
import purr.base;
import purr.vm;
import purr.fs.files;
import purr.fs.disk;
import purr.io;
import std.conv;

Pair[] libio()
{
    Pair[] ret = [
        FunctionPair!libprint("print"),
        FunctionPair!libput("put"),
        FunctionPair!libreadln("readln"),
        FunctionPair!libread("read"),
        FunctionPair!libget("get"),
        FunctionPair!libslurp("slurp"),
        FunctionPair!libdump("dump"),
        FunctionPair!libsync("sync"),
    ];
    return ret;
}

/// prints with newline
Dynamic libprint(Args args)
{
    foreach (i; args)
    {
        if (i.type == Dynamic.Type.str)
        {
            write(i.to!string[1..$-1]);
        }
        else
        {
            write(i);
        }
    }
    writeln;
    stdout.flush;
    return Dynamic.nil;
}

/// prints without newline
Dynamic libput(Args args)
{
    foreach (i; args)
    {
        if (i.type == Dynamic.Type.str)
        {
            write(i.to!string[1..$-1]);
        }
        else
        {
            write(i);
        }
    }
    stdout.flush;
    return Dynamic.nil;
}

/// reads until newline
Dynamic libreadln(Args args)
{
    string prompt;
    if (args.length > 0)
    {
        prompt = args[0].str;
    }
    return dynamic(prompt.readln[0 .. $ - 1]);
}

Dynamic libget(Args args)
{
    size_t count = 1;
    if (args.length > 0)
    {
        count = args[0].as!size_t;
    }
    string ret;
    foreach (i; 0..count)
    {
        ret ~= getchar;
    }
    return ret.dynamic;
}

Dynamic libread(Args args)
{
    size_t count = 1;
    if (args.length > 0)
    {
        count = args[0].as!size_t;
    }
    string ret;
    foreach (i; 0..count)
    {
        ret ~= readchar;
    }
    return ret.dynamic;
}

/// writes a string to a file
Dynamic libdump(Args args)
{
    args[0].str.dumpToFile(args[1].str);
    return Dynamic.nil;
}

/// sync file from filesystem
Dynamic libsync(Args args)
{
    return args[0].str.syncFile.dynamic;
} 
/// reads an entire file
Dynamic libslurp(Args args)
{
    return args[0].str.readFile.src.dynamic;
}

module purr.error;

version(X86)
{
    alias LangException = Exception;
    alias RuntimeException = LangException;
    alias TypeException = RuntimeException;
    alias AssertException = RuntimeException;
    alias BoundsException = RuntimeException;
    alias CompileException = LangException;
    alias ParseException = LangException;
    alias UndefinedException = LangException;
}
version(X86_64)
{
    class LangException : Exception
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null)
        {
            super(msg, file, line, nextInChain);
        }
    }

    class RuntimeException : LangException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }

    class TypeException : RuntimeException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }

    class AssertException : RuntimeException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }

    class BoundsException : RuntimeException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }
    class CompileException : LangException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }

    class ParseException : CompileException
    {
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            super(msg, file, line, nextInChain);
        }
    }

    class UndefinedException : CompileException
    {
        string undef;
        this(string msg, string file = __FILE__, size_t line = __LINE__, Throwable nextInChain = null) 
        {
            undef = msg;
            super("not defined: " ~ msg, file, line, nextInChain);
        }
    }
}
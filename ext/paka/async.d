module ext.paka.async;

import core.memory;
import std.conv;
import purr.io;
import purr.dynamic;

Dynamic awaitOp(Args args)
{
    return args[0].async!true;
}
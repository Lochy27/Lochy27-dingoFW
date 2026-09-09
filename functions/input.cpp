#include "input.h"
#include "debug_log.h"

bool Input::Check(InputMode eMode, bool bInvert, bool bVal)
{
    bool bPrevious = bLast;
    bVal = bVal ^ bInvert;

    if (bVal != bLast)
    {
        if (eMode == InputMode::Momentary)
            bOut = bVal;
        else if ((eMode == InputMode::Latching) && 
                 (bVal == true))
            bOut = !bOut;
    }

    bLast = bVal;

    if (bVal != bPrevious)
    {
        DebugStr("Input mode="); DebugHex(static_cast<uint32_t>(eMode));
        DebugStr(" raw="); DebugHex(static_cast<uint32_t>(bVal));
        DebugStr(" last="); DebugHex(static_cast<uint32_t>(bPrevious));
        DebugStr(" out="); DebugHex(static_cast<uint32_t>(bOut));
        DebugStr("\r\n");
    }

    return bOut;
}
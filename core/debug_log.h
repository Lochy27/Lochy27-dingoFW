#pragma once

// Lightweight SWO (ITM) debug logging. View via Cortex-Debug's SWO console (no extra hardware/wiring beyond the ST-Link).
// Remove/disable before shipping - it stalls if no debugger is attached to drain the ITM FIFO.

#include "hal.h"

#define DEBUG_LOG_ENABLED 1

#if DEBUG_LOG_ENABLED

static inline void DebugChar(char c)
{
    ITM_SendChar((uint32_t)c);
}

static inline void DebugStr(const char* s)
{
    while (*s)
        DebugChar(*s++);
}

static inline void DebugHex(uint32_t val)
{
    static const char hex[] = "0123456789ABCDEF";
    DebugStr("0x");
    for (int8_t i = 7; i >= 0; i--)
        DebugChar(hex[(val >> (i * 4)) & 0xF]);
}

#else

static inline void DebugChar(char) {}
static inline void DebugStr(const char*) {}
static inline void DebugHex(uint32_t) {}

#endif

#include "ch.h"
#include "hal.h"
#include "device.h"
#include "debug_log.h"

/*
 * Application entry point.
 */
int main(void) {
  

  halInit();
  chSysInit();
  
  chThdSleepMilliseconds(500);
  
  InitDevice();
  
  uint32_t nHeartbeat = 0;
  while (true) {
    DebugStr("heartbeat "); DebugHex(nHeartbeat++); DebugStr("\r\n");
    chThdSleepMilliseconds(500);
  }
}

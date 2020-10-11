#include "RTOS.h"

/*********************************************************************
*
*       SysTick_Handler()
*
*  Function description
*    This is the hardware timer exception handler.
*/
void SysTick_Handler(void) {
  OS_INT_EnterNestable();
  OS_TICK_Handle();
  OS_INT_LeaveNestable();
}

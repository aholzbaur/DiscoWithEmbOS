#include "RTOS.h"

int main(void) {
  OS_Init();    // Initialize embOS
  OS_Start();   // Start embOS
  return 0;
}

#include "RTOS.h"

#include "leds/leds-service.hpp"

int main(void) {
  leds_service* p_leds_service = leds_service_get_instance();

  OS_Init();    // Initialize embOS

  if (p_leds_service->initialize() != 0) return -1;

  leds_service* second = new leds_service();
  if (second->initialize() != 0) return -1;

  OS_Start();   // Start embOS
  return 0;
}

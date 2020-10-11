#include "leds-service.hpp"

#include "RTOS.h"

static const unsigned int LEDS_SERVICE_TASK_PRIO = 20u;
static const unsigned int LEDS_SERVICE_TASK_STACK_SIZE = 64u;
static const char LEDS_SERVICE_TASK_NAME[] = "leds_service_task";
static leds_service leds_service_g;

static OS_TASK LEDS_SERVICE_TASK;
static OS_STACKPTR int LEDS_SERVICE_TASK_STACK[LEDS_SERVICE_TASK_STACK_SIZE];

static void leds_service_task() {
  for (;;) {
  }
}

leds_service::leds_service() {
  this->initialized = false;
}

int leds_service::initialize() {
  if (this == leds_service_get_instance()) {
    if (this->initialized != true) {
      OS_CREATETASK(&LEDS_SERVICE_TASK, LEDS_SERVICE_TASK_NAME, leds_service_task, LEDS_SERVICE_TASK_PRIO, LEDS_SERVICE_TASK_STACK);
      this->initialized = true;
      return 0;
    }
  }
  return -1;
}

leds_service *leds_service_get_instance() {
  return &leds_service_g;
}
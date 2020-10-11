#ifndef __LEDS_SERVICE_HPP_
#define __LEDS_SERVICE_HPP_

class leds_service {
public:
  leds_service();
  int initialize();

private:
  bool initialized;
};

leds_service *leds_service_get_instance();

#endif // __LEDS_SERVICE_HPP_
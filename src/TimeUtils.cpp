#include <inttypes.h>

extern "C" {
  uint32_t millis() {return 0;}
  void delay(uint32_t ) {}
}


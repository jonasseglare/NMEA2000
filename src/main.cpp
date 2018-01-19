#include <iostream>
#include <NMEA2000.h>
#include <inttypes.h>

#define CRASH(x) {std::cerr << "ERROR: " << (x) << std::endl; abort();}

class NullNMEA2000 : public tNMEA2000 {
public:
  bool isFastPacketPGN(uint64_t x) {
    return IsFastPacketPGN(x);
  }

  bool CANSendFrame(unsigned long id, unsigned char len, 
                    const unsigned char *buf, bool wait_sent=true) {
    CRASH("Not implemented");
  }
  virtual bool CANOpen() {
    CRASH("Not implemented");
  }
  virtual bool CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf) {
    CRASH("Not implemented");
  }

};

int main() {
  NullNMEA2000 instance;

  while (true) {
    uint64_t x = 0;
    std::cin >> x;
    std::cout << instance.isFastPacketPGN(x) << " ";
  }
  return 0;
}

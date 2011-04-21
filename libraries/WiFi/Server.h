#ifndef Server_h
#define Server_h

extern "C" {
  #include "utility/wl_definitions.h"
}

#include "Print.h"

class Client;

class Server : public Print {
private:
  uint16_t _port;
  void*     pcb;
public:
  Server(uint16_t);
  Client available(uint8_t*);
  void begin();
  virtual void write(uint8_t);
  virtual void write(const char *str);
  virtual void write(const uint8_t *buf, size_t size);
};

#endif
#ifndef _NMEA2000_STM32_H_
#define _NMEA2000_STM32_H_

#include "stm32_can.h"
#include "NMEA2000.h"

class tNMEA2000_stm32 : public tNMEA2000
{
protected:
  uint16_t DefTimeOut; 
  uint8_t NumTxMailBoxes;
  bool CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent);
  bool CANOpen();
  bool CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf);
  void InitCANFrameBuffers();
  
public:
  tNMEA2000_stm32(uint16_t _DefTimeOut=4, uint8_t CANBusIndex=0);
};

#endif
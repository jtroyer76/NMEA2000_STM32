#include "NMEA2000_STM32.h"
#include "stm32_can.h"

//*****************************************************************************
tNMEA2000_stm32::tNMEA2000_stm32(uint16_t _DefTimeOut, uint8_t CANBusIndex) : tNMEA2000() {
}

bool tNMEA2000_stm32::CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent) {
  CAN_msg_t out;
  out.id = id;
  out.len = len;
  
    // Fill the frame buffer
  for (int i=0; i<len && i<8; i++) out.data[i] = buf[i];

  CANSend(&out);
  return true;
}

bool tNMEA2000_stm32::CANOpen() {
  CANInit(CAN_250KBPS);
  return true;
}

bool tNMEA2000_stm32::CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf) {
  CAN_msg_t incoming;
  
  if (CANMsgAvail()) {
    CANReceive(&incoming);
    id = incoming.id;
    len = incoming.len;
    for (int i = 0; i < len && i < 8; i++) {
      buf[i] = incoming.data[i];
    }
    return true;
  }
  else {
    return false;
  }
}

void tNMEA2000_stm32::InitCANFrameBuffers() {
  
}

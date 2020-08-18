
#ifndef _STM32_CAN_H
#define _STM32_CAN_H

#include <Arduino.h>

enum BITRATE{CAN_50KBPS, CAN_100KBPS, CAN_125KBPS, CAN_250KBPS, CAN_500KBPS, CAN_1000KBPS};

typedef struct
{
  uint32_t id;
  uint8_t  data[8];
  uint8_t  len;
} CAN_msg_t;

typedef const struct
{
  uint8_t TS2;
  uint8_t TS1;
  uint8_t BRP;
} CAN_bit_timing_config_t;

extern CAN_bit_timing_config_t can_configs[6];
CAN_bit_timing_config_t can_configs[6] = {{2, 13, 45}, {2, 15, 20}, {2, 13, 18}, {2, 13, 9}, {2, 15, 4}, {2, 15, 2}};

void CANInit(enum BITRATE bitrate);
void CANSetFilter(uint16_t id);
void CANSetFilters(uint16_t* ids, uint8_t num);
void CANReceive(CAN_msg_t* CAN_rx_msg);
void CANSend(CAN_msg_t* CAN_tx_msg);
uint8_t CANMsgAvail(void);

#endif
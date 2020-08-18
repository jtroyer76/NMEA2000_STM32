# NMEA2000_STM32
A driver for the NMEA2000 library and STM32 devices.  Tested on STM32F103C8 - Bluepill



    #include <Arduino.h>

    #include <NMEA2000_stm32.h>
    #include <NMEA2000.h>
    #include <N2kMessages.h>

    tNMEA2000_stm32 NMEA2000;
    
This library is not integrated into the NMEA2000 library so using the NMEA2000_CAN header will not work.  Use the headers as shown above and it will work for CAN on STM32. 

Defaults to using PA11, PA12 but can be changed in stm32_can.cpp see commented code.
    

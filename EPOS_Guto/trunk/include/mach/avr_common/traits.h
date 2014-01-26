#ifndef __avrcommon_traits_h
#define __avrcommon_traits_h

#include <system/config.h>

__BEGIN_SYS

class AVR_Common;
template <> struct Traits<AVR_Common>: public Traits<void>
{
};

class AVR_Machine;
template <> struct Traits<AVR_Machine>: public Traits<AVR_Common>
{
    static const unsigned int MAX_CPUS = 1;
};

class AVR_UART;
template <> struct Traits<AVR_UART>: public Traits<void>
{
    enum Power_Modes
    {
		FULL                = 0,//Tx AND Rx enabled
		LIGHT               = 1,//Only Tx enabled
		STANDBY             = 2,//Only Rx enabled
		OFF                 = 3 //Tx AND Rx disabled
    };
    static const bool power_management = true;
};

class AVR_ADC;
template <> struct Traits<AVR_ADC>: public Traits<void>
{
    typedef enum Power_Modes
    {
		FULL                = 0,
		LIGHT               = 1, //The same as FULL
		STANDBY             = 2,
		OFF                 = 3  //The same as STANDBY
    };
    static const bool power_management = true;
};

__END_SYS

#endif

// EPOS-- Configuration Engine
//

#ifndef __config_h
#define __config_h

//============================================================================
// DEFINITIONS
//============================================================================
#define __SYS_NS		System
#define __BEGIN_SYS		namespace __SYS_NS {
#define __END_SYS		}
#define __USING_SYS		using namespace __SYS_NS;
#define __SYS(X)		::__SYS_NS::X

#define ASM                     __asm__
#define ASMV                    __asm__ __volatile__

#define __HEADER_ARCH(X)        <arch/ARCH/X.h>
#define __HEADER_MACH(X)        <mach/MACH/X.h>

//============================================================================
// CONFIGURATION
//============================================================================
#include <system/types.h>
#include <system/meta.h>
#include <traits.h>

__BEGIN_SYS

// Architecture configuration
#if defined (__ia32)

#define ARCH ia32
typedef IA32			CPU;
typedef IA32_MMU		MMU;
typedef IA32_TSC		TSC;
#define __CPU_H			__HEADER_ARCH(cpu)
#define __TSC_H			__HEADER_ARCH(tsc)
#define __MMU_H			__HEADER_ARCH(mmu)

#elif defined (__avr8)

#define ARCH avr8
typedef AVR8			CPU;
typedef AVR8_MMU		MMU;
typedef AVR8_TSC		TSC;
#define __CPU_H			__HEADER_ARCH(cpu)
#define __TSC_H			__HEADER_ARCH(tsc)
#define __MMU_H			__HEADER_ARCH(mmu)

#elif defined (__ppc32)

#define ARCH ppc32
typedef PPC32                    CPU;
typedef PPC32_MMU                MMU;
typedef PPC32_TSC                TSC;
#define __CPU_H                 __HEADER_ARCH(cpu)
#define __TSC_H                 __HEADER_ARCH(tsc)
#define __MMU_H                 __HEADER_ARCH(mmu)

#elif defined (__mips32)

#define ARCH mips32
typedef MIPS32                  CPU;
typedef MIPS32_MMU              MMU;
typedef MIPS32_TSC              TSC;
#define __CPU_H                 __HEADER_ARCH(cpu)
#define __TSC_H                 __HEADER_ARCH(tsc)
#define __MMU_H                 __HEADER_ARCH(mmu)

#else
#error Architecture not selected!
#endif

// Machine configuration
#if defined (__pc)

#define MACH			pc
typedef PC			Machine;
typedef PC_PCI			PCI;
typedef PC_IC			IC;
typedef PC_Timer		Timer;
typedef PC_RTC			RTC;
typedef PC_EEPROM		EEPROM;
typedef PC_UART			UART;
typedef Dummy<0>		SPI;
typedef IF<Traits<PC_Display>::on_serial,
	   Serial_Display,
	   PC_Display>::Result	Display;
typedef PC_NIC			NIC;
typedef Dummy<1>		ADC;
typedef Dummy<2>		Temperature_Sensor;
typedef Dummy<3>		Photo_Sensor;
typedef Dummy<4>		Accelerometer;
typedef Dummy<5>		Humidity_Sensor;
#define __MACH_H		__HEADER_MACH(machine)
#define __PCI_H			__HEADER_MACH(pci)
#define __IC_H			__HEADER_MACH(ic)
#define __TIMER_H		__HEADER_MACH(timer)
#define __RTC_H			__HEADER_MACH(rtc)
#define __EEPROM_H		__HEADER_MACH(eeprom)
#define __UART_H		__HEADER_MACH(uart)
#define __DISPLAY_H		__HEADER_MACH(display)
#define __NIC_H			__HEADER_MACH(nic)

#elif defined (__atmega16)

#define MACH atmega16
typedef ATMega16		Machine;
typedef ATMega16_IC		IC;
typedef ATMega16_Timer		Timer;
typedef ATMega16_RTC		RTC;
typedef ATMega16_EEPROM		EEPROM;
typedef Dummy<0>		PCI;
typedef ATMega16_UART		UART;
typedef ATMega16_SPI		SPI;
typedef IF<Traits<ATMega16_Display>::on_serial,
	   Serial_Display,
	   PC_Display>::Result	Display;
typedef ATMega16_NIC		NIC;
typedef ATMega16_ADC		ADC;
typedef Dummy<1>		Temperature_Sensor;
typedef Dummy<2>		Photo_Sensor;
typedef Dummy<3>		Accelerometer;
typedef Dummy<4>		Humidity_Sensor;
#define __MACH_H		__HEADER_MACH(machine)
#define __IC_H			__HEADER_MACH(ic)
#define __TIMER_H		__HEADER_MACH(timer)
#define __RTC_H			__HEADER_MACH(rtc)
#define __EEPROM_H		__HEADER_MACH(eeprom)
#define __UART_H		__HEADER_MACH(uart)
#define __SPI_H			__HEADER_MACH(spi)
#define __NIC_H			__HEADER_MACH(nic)
#define __ADC_H			__HEADER_MACH(adc)

#elif defined (__atmega128)

#define MACH atmega128
typedef ATMega128		Machine;
typedef ATMega128_IC		IC;
typedef ATMega128_Timer		Timer;
typedef ATMega128_RTC		RTC;
typedef ATMega128_EEPROM	EEPROM;
typedef Dummy<0>		PCI;
typedef ATMega128_UART		UART;
typedef ATMega128_SPI		SPI;
typedef IF<Traits<ATMega128_Display>::on_serial,
	   Serial_Display,
	   PC_Display>::Result	Display;
typedef ATMega128_NIC		NIC;
typedef ATMega128_ADC		ADC;
typedef ATMega128_Temperature_Sensor	Temperature_Sensor;
typedef ATMega128_Photo_Sensor	Photo_Sensor;
typedef ATMega128_Accelerometer	Accelerometer;
typedef Dummy<1>		Humidity_Sensor;
#define __MACH_H		__HEADER_MACH(machine)
#define __IC_H			__HEADER_MACH(ic)
#define __TIMER_H		__HEADER_MACH(timer)
#define __RTC_H			__HEADER_MACH(rtc)
#define __EEPROM_H		__HEADER_MACH(eeprom)
#define __UART_H		__HEADER_MACH(uart)
#define __SPI_H			__HEADER_MACH(spi)
#define __NIC_H			__HEADER_MACH(nic)
#define __ADC_H			__HEADER_MACH(adc)
#define __SENSOR_H		__HEADER_MACH(sensor)

#elif defined (__atmega1281)

#define MACH atmega1281
typedef ATMega1281		Machine;
typedef ATMega1281_IC		IC;
typedef ATMega1281_Timer	Timer;
typedef ATMega1281_Timer_3 CMAC_timer;
typedef ATMega1281_RTC		RTC;
typedef ATMega1281_EEPROM	EEPROM;
typedef Dummy<0>		PCI;
typedef ATMega1281_UART		UART;
typedef ATMega1281_SPI		SPI;
typedef IF<Traits<ATMega1281_Display>::on_serial,
	   Serial_Display,
	   PC_Display>::Result	Display;
typedef ATMega1281_Transceiver	Transceiver;
typedef ATMega1281_NIC		NIC;
typedef ATMega1281_ADC		ADC;
typedef ATMega1281_Temperature_Sensor	Temperature_Sensor;
typedef Dummy<1>		Photo_Sensor;
typedef Dummy<2>		Accelerometer;
typedef ATMega1281_Humidity_Sensor Humidity_Sensor;
#define __MACH_H		__HEADER_MACH(machine)
#define __IC_H			__HEADER_MACH(ic)
#define __TIMER_H		__HEADER_MACH(timer)
#define __RTC_H			__HEADER_MACH(rtc)
#define __EEPROM_H		__HEADER_MACH(eeprom)
#define __UART_H		__HEADER_MACH(uart)
#define __SPI_H			__HEADER_MACH(spi)
#define __TRANSCEIVER_H	__HEADER_MACH(transceiver)
#define __NIC_H			__HEADER_MACH(nic)
#define __ADC_H			__HEADER_MACH(adc)
#define __SENSOR_H		__HEADER_MACH(sensor)

#elif defined (__ml310)

#define MACH                    ml310
typedef ML310                   Machine;
typedef ML310_PCI               PCI;
typedef ML310_IC                IC;
typedef ML310_Timer             Timer;
typedef ML310_RTC               RTC;
typedef Dummy<0>                EEPROM;
typedef ML310_UART              UART;
typedef Dummy<1>                SPI;
typedef Serial_Display          Display;
typedef ML310_NIC               NIC;
typedef Dummy<2>                ADC;
typedef Dummy<3>                Temperature_Sensor;
typedef Dummy<4>                Photo_Sensor;
typedef Dummy<5>		Accelerometer;
typedef Dummy<6>		Humidity_Sensor;
#define __MACH_H                __HEADER_MACH(machine)
#define __PCI_H                 __HEADER_MACH(pci)
#define __IC_H                  __HEADER_MACH(ic)
#define __TIMER_H               __HEADER_MACH(timer)
#define __RTC_H                 __HEADER_MACH(rtc)
#define __UART_H                __HEADER_MACH(uart)
#define __NIC_H                 __HEADER_MACH(nic)

#elif defined (__plasma)

#define MACH                    plasma
typedef PLASMA                  Machine;
typedef Dummy<0>                PCI;
typedef PLASMA_IC               IC;
typedef PLASMA_Timer            Timer;
typedef PLASMA_RTC              RTC;
typedef Dummy<1>                EEPROM;
typedef PLASMA_UART             UART;
typedef Dummy<2>                SPI;
typedef Serial_Display          Display;
typedef PLASMA_NIC              NIC;
typedef Dummy<3>                ADC;
typedef Dummy<4>                Temperature_Sensor;
typedef Dummy<5>                Photo_Sensor;
typedef Dummy<6>                Accelerometer;
typedef Dummy<7>		Humidity_Sensor;
#define __MACH_H                __HEADER_MACH(machine)
#define __PCI_H                 __HEADER_MACH(pci)
#define __IC_H                  __HEADER_MACH(ic)
#define __TIMER_H               __HEADER_MACH(timer)
#define __RTC_H                 __HEADER_MACH(rtc)
#define __UART_H                __HEADER_MACH(uart)
#define __NIC_H                 __HEADER_MACH(nic)
#define __RTC_H                 __HEADER_MACH(rtc)

#else
#error Machine not selected!
#endif

__END_SYS

#include <system/ctti.h>
#include <system/info.h>

//============================================================================
// THINGS EVERBODY NEEDS
//============================================================================
#include <utility/ostream.h>
#include <utility/debug.h>

#endif



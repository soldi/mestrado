#ifndef __pc_traits_h
#define __pc_traits_h

#include <system/config.h>

__BEGIN_SYS

class PC_Common;
template <> struct Traits<PC_Common>: public Traits<void>
{
    static const bool debugged = Traits<void>::debugged;
};

template <> struct Traits<PC>: public Traits<PC_Common>
{
    static const unsigned int MAX_CPUS = 8;

    // Boot Image
    static const unsigned int BOOT_LENGTH_MIN   = 128;
    static const unsigned int BOOT_LENGTH_MAX   = 512;
    static const unsigned int BOOT_IMAGE_ADDR   = 0x00008000;

    // Physical Memory
    static const unsigned int MEM_BASE  = 0x00000000;
    static const unsigned int MEM_TOP   = 0x02000000;

    // Logical Memory Map
    static const unsigned int BOOT      = 0x00007c00;
    static const unsigned int SETUP     = 0x00100000;
    static const unsigned int INIT      = 0x00200000;

    static const unsigned int APP_LOW   = 0x00008000;
    static const unsigned int APP_CODE  = 0x00008000;
    static const unsigned int APP_DATA  = 0x00400000;
    static const unsigned int APP_HIGH  = 0x0fffffff;

    static const unsigned int PHY_MEM   = 0x10000000;
    static const unsigned int IO_BASE   = 0x20000000;
    static const unsigned int IO_TOP    = 0x1f400000;

    static const unsigned int SYS       = IO_TOP;
    static const unsigned int SYS_CODE  = 0xff700000;
    static const unsigned int SYS_DATA  = 0xff740000;
};

template <> struct Traits<PC_PCI>: public Traits<PC_Common>
{
    static const int MAX_BUS = 0;
    static const int MAX_DEV_FN = 0xff;
};

template <> struct Traits<PC_IC>: public Traits<PC_Common>
{
};

template <> struct Traits<PC_Timer>: public Traits<PC_Common>
{
    // Meaningful values for the PC's timer frequency range from 100 to
    // 10000 Hz. The choice must respect the scheduler time-slice, i. e.,
    // it must be higher than the scheduler invocation frequency.
    static const int FREQUENCY = 1000; // Hz
};

template <> struct Traits<PC_RTC>: public Traits<PC_Common>
{
    static const unsigned int EPOCH_DAY = 1;
    static const unsigned int EPOCH_MONTH = 1;
    static const unsigned int EPOCH_YEAR = 1970;
    static const unsigned int EPOCH_DAYS = 719499;
};

template <> struct Traits<PC_EEPROM>: public Traits<PC_Common>
{
};

template <> struct Traits<PC_UART>: public Traits<PC_Common>
{
    static const unsigned int CLOCK = 1843200; // 1.8432 MHz
    static const unsigned int COM1 = 0x3f8; // to 0x3ff, IRQ4
    static const unsigned int COM2 = 0x2f8; // to 0x2ff, IRQ3
    static const unsigned int COM3 = 0x3e8; // to 0x3ef, no IRQ
    static const unsigned int COM4 = 0x2e8; // to 0x2ef, no IRQ
};

template <> struct Traits<PC_Display>: public Traits<PC_Common>
{
    static const int COLUMNS = 80;
    static const int LINES = 25;
    static const int TAB_SIZE = 8;
    static const unsigned int FRAME_BUFFER_ADDRESS = 0xb8000;
};

template <> struct Traits<PC_Ethernet>: public Traits<PC_Common>
{
    static const bool enabled = false;
    typedef LIST<PCNet32> NICS;
};

template <> struct Traits<PCNet32>: public Traits<PC_Ethernet>
{
    static const unsigned int UNITS = NICS::Count<PCNet32>::Result;
    static const unsigned int SEND_BUFFERS = 8; // per unit
    static const unsigned int RECEIVE_BUFFERS = 8; // per unit
};

template <> struct Traits<E100>: public Traits<PC_Ethernet>
{
    static const unsigned int UNITS = NICS::Count<E100>::Result;
    static const unsigned int SEND_BUFFERS = 8; // per unit
    static const unsigned int RECEIVE_BUFFERS = 8; // per unit
};

template <> struct Traits<C905>: public Traits<PC_Ethernet>
{
    static const unsigned int UNITS = NICS::Count<C905>::Result;
    static const unsigned int SEND_BUFFERS = 8; // per unit
    static const unsigned int RECEIVE_BUFFERS = 8; // per unit
};

template <> struct Traits<PC_Scratchpad>: public Traits<PC_Common>
{
    static const bool enabled = false;
    static const unsigned int ADDRESS = Traits<PC_Display>::FRAME_BUFFER_ADDRESS;
    static const unsigned int SIZE = Traits<PC_Display>::LINES * Traits<PC_Display>::COLUMNS;
};

__END_SYS

#endif
// EPOS-- ATMega128 Radio (CC1000) NIC Mediator Initialization

#include <system/kmalloc.h>
#include <mach/atmega128/machine.h>
#include <mach/atmega128/radio.h>

__BEGIN_SYS

void Radio::init(unsigned int unit)
{
    db<Init, Radio>(TRC) << "Radio::init(unit=" << unit << ")\n";
}

__END_SYS

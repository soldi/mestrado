// EPOS-- PC Mediator Initialization

#include <machine.h>

__BEGIN_SYS

void PC::init()
{
    db<Init, PC>(TRC) << "PC::init()\n";

    if(Traits<PC_IC>::enabled)
	PC_IC::init();
    if(Traits<PC_PCI>::enabled)
	PC_PCI::init();
    if(Traits<PC_Timer>::enabled)
	PC_Timer::init();
    if(Traits<PC_NIC>::enabled)
	PC_NIC::init();
}

__END_SYS

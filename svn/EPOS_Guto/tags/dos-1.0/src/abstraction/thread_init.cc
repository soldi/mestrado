// EPOS-- Thread Abstraction Initialization

#include <thread.h>
#include <alarm.h>
#include <system/kmalloc.h>

__BEGIN_SYS

int Thread::init(System_Info * si)
{
    db<Init>(TRC) << "Thread::init(entry="
		  << (void *)si->lmm.app_entry << ")\n";

    if(Traits::active_scheduler)
	Alarm::master(Traits::quantum, &reschedule);

    _running = 	new(malloc(sizeof(Thread))) 
	Thread(reinterpret_cast<int (*)()>(si->lmm.app_entry), RUNNING);
    _running->_context->load();

    return 0;
}

__END_SYS

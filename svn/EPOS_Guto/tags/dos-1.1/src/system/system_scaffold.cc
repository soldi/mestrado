// EPOS System Scaffold and System Abstraction Implementation

#include <utility/ostream.h>
#include <utility/heap.h>
#include <machine.h>
#include <thread.h>
#include <system.h>
#include <display.h>

// LIBC Heritage

__USING_SYS

extern "C" {
    void _exit(int s) {
        Thread::exit(s); for(;;);
    }

    void __cxa_pure_virtual() {
        db<void>(ERR) << "__cxa_pure_virtual() called!\n";
        Machine::panic();
    }
}

__BEGIN_SYS

// This class purpose is simply to define a well-known entry point for 
// the system. It must be declared as the first global object in
// system_scaffold.cc
class First_Object
{
public:
    First_Object() {
        Display::remap();
    }
};

// Global objects
// These objects might be reconstructed several times in multicore configurations,
// so their constructors must be stateless!
First_Object __entry;
OStream kout;
OStream kerr;

// System class attributes
System_Info<Machine> * System::_si =
    reinterpret_cast<System_Info<Machine> *>(Memory_Map<Machine>::SYS_INFO);

Heap System::_heap;

System_Info<Machine> * const System::info() { return _si; }

__END_SYS

/*! @file
 *  @brief EPOS Semaphore Abstraction Declarations
 *
 *  CVS Log for this file:
 *  \verbinclude include/semaphore_h.log
 */
#ifndef __semaphore_h
#define __semaphore_h

#include <utility/handler.h>
#include <common/synchronizer.h>

__BEGIN_SYS

class Semaphore: public Synchronizer_Common
{
public:
    Semaphore(int v = 1) : _value(v) {
	db<Synchronizer>(TRC) << "Semaphore(value= " << _value << ") => "
			      << this << "\n";
    }
    ~Semaphore() {
	db<Synchronizer>(TRC) << "~Semaphore(this=" << this << ")\n";
    }

    void p() { 
	db<Synchronizer>(TRC) << "Semaphore::p(this=" << this 
			      << ",value=" << _value << ")\n";
	if(fdec(_value) < 1)
	    sleep();
    }
    void v() {
	db<Synchronizer>(TRC) << "Semaphore::v(this=" << this
			      << ",value=" << _value << ")\n";
	if(finc(_value) < 0)
	    wakeup();
    }

private:
    volatile int _value;
};

class Handler_Semaphore: public Handler
{
public:
    Handler_Semaphore(Semaphore * h) : _handler(h) {}

    void operator()() { _handler->v(); }
	
private:
    Semaphore * _handler;
};

__END_SYS

#endif
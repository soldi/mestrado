// EPOS-- ATMega1281 ADC Mediator Declarations

#ifndef __atmega1281_adc_h
#define __atmega1281_adc_h

#include "../avr_common/adc.h"

__BEGIN_SYS

class ATMega1281_ADC: public ADC_Common, private AVR_ADC
{
public:
    ATMega1281_ADC() : AVR_ADC(SINGLE_ENDED_ADC0, SYSTEM_REF,
			      SINGLE_CONVERSION_MODE, CLOCK >> 7) {}
    ATMega1281_ADC(unsigned char channel, Hertz frequency) 
	: AVR_ADC(channel, SYSTEM_REF, SINGLE_CONVERSION_MODE, frequency) {}
    ATMega1281_ADC(unsigned char channel, unsigned char reference,
		  unsigned char trigger, Hertz frequency) 
	: AVR_ADC(channel, reference, trigger, frequency) {}

    void config(unsigned char channel, unsigned char reference,
		unsigned char trigger, Hertz frequency) {
	AVR_ADC::config(channel, reference, trigger, frequency);
    }
    void config(unsigned char * channel, unsigned char * reference,
		unsigned char * trigger, Hertz * frequency) {
	AVR_ADC::config(channel, reference, trigger, frequency);
    }
    
    int sample() { return AVR_ADC::sample(); }
    int get() { return AVR_ADC::get(); }
    bool finished() { return AVR_ADC::finished(); }

    void reset() { return AVR_ADC::reset(); }
};

__END_SYS

#endif


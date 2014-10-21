// OpenEPOS EMote2ARM_UART Mediator Declarations

#ifndef __emote2arm_uart_h
#define __emote2arm_uart_h

#include <uart.h>
#include <cpu.h>
#include "memory_map.h"

__BEGIN_SYS

class EMote2ARM_UART: public UART_Common
{
private:
    typedef IO_Map<Machine> IO;
    typedef CPU::Reg8 Reg8;
    typedef CPU::Reg16 Reg16;
    typedef CPU::Reg32 Reg32;

public:
	//UART IO Register Bit Offsets
	enum {
		// UCON
		TST =		15,
		MRXR =		14,
		MTXR =		13,
		FCE =		12,
		FCP =		11,
		XTIM =		10,
		TX_OEN_B =	7,
		CONTX =		6,
		SB =		5,
		ST2 =		4,
		EP =		3,
		PEN =		2,
		RXE =		1,
		TXE =		0,
		// UBRCNT
		UBRINC =	16,
		UBRMOD =	0
	};

	EMote2ARM_UART(unsigned int unit = 0) : _unit(unit) {
		config(9600, 8, 0, 1);
		func_sel();
	}
    
	EMote2ARM_UART(unsigned int baud, unsigned int data_bits,
			unsigned int parity, unsigned int stop_bits,
			unsigned int unit = 0) : _unit(unit) {
	    config(baud, data_bits, parity, stop_bits);
		func_sel();
	}

	~EMote2ARM_UART() {
		// while(((utxcon() != 32) || (urxcon() != 0)));
		ucon(0x0000);
	}

	void config(unsigned int baud, unsigned int data_bits,
			unsigned int parity, unsigned int stop_bits) {
		// while(((utxcon()) != 32) || (urxcon() != 0));

		if(parity == 1) {
			parity = 0x3;
		} else if(parity == 2) {
			parity = 0x1;
		}

		ucon(0x0000);
		ucts(15);
		ubrcnt(9999 << UBRMOD |	(baud/150 -1) << UBRINC);
		ucon(1 << RXE | 1 << TXE | 1 << MRXR | 1 << MTXR |
				0 << FCE | parity << PEN | (stop_bits - 1) << ST2);
	}

	bool has_data() {
		return urxcon();
	}

	char get() {
		while(urxcon() == 0);
		return udata();
	}
    
	void put(char c) {
		while(utxcon() == 0);
		udata(c);
	}

	void loopback(bool flag) {
		if(flag) {
			ucon(ucon() | flag << TST);
		} else {
			ucon(ucon() & flag << TST);
		}
	}

private:
	Reg16 ucon() {
		return CPU::in16((_unit == 0) ? IO::UART1_UCON : IO::UART2_UCON);
	}
	void ucon(Reg16 value) { 
		CPU::out16(((_unit == 0) ? IO::UART1_UCON : IO::UART2_UCON), value);
	}   

	Reg8 ustat() {
		return CPU::in8((_unit == 0) ? IO::UART1_USTAT : IO::UART2_USTAT);
	}
	void ustat(Reg8 value) { 
		CPU::out8(((_unit == 0) ? IO::UART1_USTAT : IO::UART2_USTAT), value);
	}   

	Reg8 udata() {
		return CPU::in8((_unit == 0) ? IO::UART1_UDATA : IO::UART2_UDATA);
	}
	void udata(Reg8 value) { 
		CPU::out8(((_unit == 0) ? IO::UART1_UDATA : IO::UART2_UDATA), value);
	}   

	Reg8 urxcon() {
		return CPU::in8((_unit == 0) ? IO::UART1_URXCON : IO::UART2_URXCON);
	}
	void urxcon(Reg8 value) { 
		CPU::out8(((_unit == 0) ? IO::UART1_URXCON : IO::UART2_URXCON), value);
	}   

	Reg8 utxcon() {
		return CPU::in8((_unit == 0) ? IO::UART1_UTXCON : IO::UART2_UTXCON);
	}
	void utxcon(Reg8 value) { 
		CPU::out8(((_unit == 0) ? IO::UART1_UTXCON : IO::UART2_UTXCON), value);
	}   

	Reg8 ucts() {
		return CPU::in8((_unit == 0) ? IO::UART1_UCTS : IO::UART2_UCTS);
	}
	void ucts(Reg8 value) { 
		CPU::out8(((_unit == 0) ? IO::UART1_UCTS : IO::UART2_UCTS), value);
	}

	Reg32 ubrcnt() {
		return CPU::in32((_unit == 0) ? IO::UART1_UBRCNT : IO::UART2_UBRCNT);
	}
	void ubrcnt(Reg32 value) { 
		CPU::out32(((_unit == 0) ? IO::UART1_UBRCNT : IO::UART2_UBRCNT), value);
	}

	void func_sel() {
		Reg32 func_sel;

		if(_unit == 0) {
			func_sel = CPU::in32(IO::GPIO_FUNC_SEL0);
			CPU::out32(IO::GPIO_FUNC_SEL0, (1 << 2*14 | 1 << 2*15) |
					func_sel);
		} else {
			func_sel = CPU::in32(IO::GPIO_FUNC_SEL1);
			CPU::out32(IO::GPIO_FUNC_SEL1, (1 << 2*2 | 1 << 2*3) |
						func_sel);
		}
	}

private:
	int _unit;
};

__END_SYS

#endif
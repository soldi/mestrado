# EPOS Setup Makefile

include ../../makedefs

TARGET := $(if $(shell find $(MACH)*), install)

all:		$(TARGET)

$(MACH)_setup:	$(MACH)_setup.o
		$(LD) $(LDFLAGS) -L$(CCLIB) --omagic -Ttext=$(SETUP_ADDR) -o $@ $^ -l$(LINIT) -l$(LMACH) -l$(LARCH) -l$(LUTIL) -lgcc

install:	$(MACH)_setup
ifndef 	GDB
		$(STRIP) -o $<.tmp $<
else
		$(INSTALL) $< $<.tmp
endif
		$(INSTALL) $<.tmp $(IMG)/$<
		$(CLEAN) $<.tmp

clean:
		$(CLEAN) *.o *_setup

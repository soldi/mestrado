# EPOS Architecture Common Packages Makefile

include ../../../makedefs

OBJS := $(subst .cc,.o,$(shell find *.cc))

all:		$(LIBSYS)

$(LIBSYS):	$(LIBSYS)($(OBJS))	

clean:
		$(CLEAN) *.o

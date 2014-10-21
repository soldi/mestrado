// EPOS-- ELF Utility Declarations

#ifndef __elf_h
#define	__elf_h

#include <system/config.h>
#include "elf-linux.h"

__BEGIN_SYS

class ELF: private Elf32_Ehdr
{
public:
    ELF() {}

    bool valid() { // check for ELF magic number
	return (e_ident[EI_MAG0] == ELFMAG0) && (e_ident[EI_MAG1] == ELFMAG1)
	    && (e_ident[EI_MAG2] == ELFMAG2) && (e_ident[EI_MAG3] == ELFMAG3);
    }

    void * entry() { return (void *)((int)e_entry); }
    int segments() { return e_phnum - 1; }
    
    void * segment_address(int i) {
	return (i > segments()) ? 0 :
	    (void *)((int)(seg(i)->p_vaddr & ~(seg(i)->p_align - 1)));
    }
    int segment_size(int i) {
	return (i > segments()) ? -1 : (int)(
	    ((seg(i)->p_offset % seg(i)->p_align)
	     + seg(i)->p_memsz
	     + seg(i)->p_align - 1)
	    & ~(seg(i)->p_align - 1));
    }

    int load_segment(int i, void * addr = 0);

private:
    Elf32_Phdr * pht() { return (Elf32_Phdr *)(((char *) this) + e_phoff); }
    Elf32_Phdr * seg(int i) { return &pht()[i];  }
};

__END_SYS
 
#endif

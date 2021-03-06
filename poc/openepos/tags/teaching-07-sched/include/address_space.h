// EPOS Address_Space Abstraction Declarations

#ifndef __address_space_h
#define __address_space_h

#include <mmu.h>
#include <segment.h>

__BEGIN_SYS

class Address_Space: private MMU::Directory
{
    friend class System;
    friend class Init_System;

private:
    typedef CPU::Phy_Addr Phy_Addr;
    typedef CPU::Log_Addr Log_Addr;

    using MMU::Directory::activate;
    using MMU::Directory::pd;

protected:
    Address_Space(MMU::Page_Directory * pd);

public:
    Address_Space();
    ~Address_Space();

    Log_Addr attach(const Segment & seg);
    Log_Addr attach(const Segment & seg, Log_Addr addr);
    void detach(const Segment & seg);

    Phy_Addr physical(Log_Addr address);

    static Address_Space * self();

private:
    static void init();

private:
    static Address_Space * _master;
};

__END_SYS

#endif

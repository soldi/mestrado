// EPOS Network Abstraction Initialization

#include <network.h>

__BEGIN_SYS

template <int unit>
inline static void call_init()
{
    typedef typename Traits<Network>::NETWORKS::template Get<unit>::Result NET;

    // TODO: unit should be reset for each different NIC
    if(Traits<NET>::enabled)
        NET::init(unit);

    call_init<unit + 1>();
};

template <>
inline void call_init<Traits<Network>::NETWORKS::Length>()
{
};

void Network::init()
{
    db<Init, Network>(TRC) << "Network::init()" << endl;

    call_init<0>();
}

__END_SYS

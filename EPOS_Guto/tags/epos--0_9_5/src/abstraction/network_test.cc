// EPOS-- PC Network Abstraction Test

#include <network.h>

__USING_SYS

OStream cout;

int main()
{
    Network net;
    Network::Address to, from;
    Network::Protocol prot;
    char data[1500];

    for(int i = 0; i < 10; i++)
	net.send(Network::BROADCAST, "alguem ai?\n", 12);
    for(int i = 0; i < 10; i++) 
	net.receive(&from, data, 1500);

    Network::Statistics stat = net.statistics();
    cout << "Statistics\n"
	 << "Tx Packets: " << stat.tx_packets << "\n"
	 << "Tx Bytes:   " << stat.tx_bytes << "\n"
	 << "Rx Packets: " << stat.rx_packets << "\n"
	 << "Rx Bytes:   " << stat.rx_bytes << "\n";
};

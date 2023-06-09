#include <boost/asio.hpp>
#include <iostream>
#include "constants.h"
#include "net_common/common.h"

using namespace boost::asio;

class Server {
public:
	Server(net::Agent& agent);
	int FindFreeClientIndex() const;

	int FindExistingClientIndex(const ip::address_v4& address) const;
	bool IsClientConnected(int clientIndex) const;
	const ip::address_v4& GetClientAddress(int clientIndex) const;
	const ip::udp::endpoint GetClientEndpoint(int clientIndex) const;
	int ConnectClient(ip::udp::endpoint clientEndpoint);
	void ReceiveMessage();

	size_t SendConnectionAccepted(int index);

private:
	int maxClients;
	int numClientsConnected;
	bool clientConnected[MaxClients] = { false, false };
	ip::udp::endpoint clientEndpoints[MaxClients];
	net::Agent& agent;
};
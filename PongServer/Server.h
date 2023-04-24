#include <boost/asio.hpp>
#include "constants.h"

using namespace boost::asio;

class Server {
public:
	int FindFreeClientIndex() const;

	int FindExistingClientIndex(const ip::address_v4& address) const;
	bool IsClientConnected(int clientIndex) const;
	const ip::address_v4& GetClientAddress(int clientIndex) const;
private:
	int maxClients;
	int numClientsConnected;
	bool clientConnected[MaxClients];
	ip::address_v4 clientAddress[MaxClients];
};
#include "Server.h"

int Server::FindFreeClientIndex() const {
	for (int i = 0; i < maxClients; ++i) {
		if (!clientConnected[i])
			return i;
	}
	return -1;
}

int Server::FindExistingClientIndex(const ip::address_v4& address) const {
	for (int i = 0; i < MaxClients; ++i) {
		if (clientConnected[i] && clientAddress[i] == address)
			return i;
	}
	return -1;
}

bool Server::IsClientConnected(int clientIndex) const {
	return clientConnected[clientIndex];
}

const ip::address_v4& Server::GetClientAddress(int clientIndex) const {
	return clientAddress[clientIndex];
}
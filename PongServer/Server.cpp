#include "Server.h"

Server::Server(net::Agent& agent) :
	agent(agent),
	maxClients(MaxClients),
	numClientsConnected(0) {
}

int Server::FindFreeClientIndex() const {
	for (int i = 0; i < maxClients; ++i) {
		if (!clientConnected[i])
			return i;
	}
	return -1;
}

int Server::FindExistingClientIndex(const ip::address_v4& address) const {
	for (int i = 0; i < MaxClients; ++i) {
		if (clientConnected[i] && GetClientEndpoint(i).address().to_v4() == address)
			return i;
	}
	return -1;
}

bool Server::IsClientConnected(int clientIndex) const {
	return clientConnected[clientIndex];
}

const ip::address_v4& Server::GetClientAddress(int clientIndex) const {
	return GetClientEndpoint(clientIndex).address().to_v4();
}

const ip::udp::endpoint Server::GetClientEndpoint(int clientIndex) const {
	return clientEndpoints[clientIndex];
}

int Server::ConnectClient(ip::udp::endpoint clientEndpoint) {
	if (numClientsConnected == maxClients) {
		return -1;
	}

	int i = FindFreeClientIndex();
	if (i >= 0) {
		if (FindExistingClientIndex(clientEndpoint.address().to_v4()) != -1) {
			std::cout << "Client is already connected." << std::endl;
			return -1;
		}
		clientConnected[i] = true;
		clientEndpoints[i] = clientEndpoint;

		std::cout << "Connected client at index: " << i << std::endl;

		return i;
	}

	std::cout << "Could not connect client." << std::endl;
	return -1;
}

void Server::ReceiveMessage() {
	boost::asio::ip::udp::endpoint remote_endpoint;
	net::Packet p = agent.ReceivePacketFrom(remote_endpoint);
	std::cout << "From: " << remote_endpoint.address().to_string() << ":" << remote_endpoint.port() << ": ";
	std::vector<uint8_t> packetVector = p.BuildPacketVector();
	for (auto i : packetVector) {
		std::cout << static_cast<int>(i) << " ";
	}
	std::cout << std::endl;

	if (p.GetProtocolId() != net::Packet::DEFAULT_PROTO_ID) {
		return;
	}

	if (p.GetPacketType() == net::Packet::TYPE_CONNREQ) {
		int res = ConnectClient(remote_endpoint);
		if (res != -1) {
			SendConnectionAccepted(res);
		}
	}
}

size_t Server::SendConnectionAccepted(int index) {
	net::Packet p = net::Packet{ net::Packet::DEFAULT_PROTO_ID, net::Packet::TYPE_CONNACCEPT };
	std::vector<uint8_t> data = { static_cast<uint8_t>(index) };
	
	p.SetData(data);

	return agent.SendPacketTo(p, clientEndpoints[index]);
}
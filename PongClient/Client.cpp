#include "Client.h"

Client::Client(net::Agent& agent) :
	agent(agent) {
	connectionState = Disconnected;
}

size_t Client::AttemptConnection() {
	net::Packet p = net::Packet{ net::Packet::DEFAULT_PROTO_ID, net::Packet::TYPE_CONNREQ };
	std::vector<uint8_t> dataVector{};
	return SendToServer(p);
}

size_t Client::SendToServer(net::Packet p) {
	return agent.SendPacket(p);
}

net::Packet Client::ReceiveMessage() {
	return agent.ReceivePacket();
}
#include "agent.h"
#include <iostream>

namespace net {
	Agent::Agent(asio::io_context& io_context, std::string receiverIp, std::string receiverPort) :
		io_context(io_context),
		socket(asio::ip::udp::socket(io_context)),
		receiverIpString(receiverIp),
		receiverPortString(receiverPort)
	{
		socket.open(asio::ip::udp::v4());
		ResolveEndpoint(receiverIpString, receiverPortString);
	};

	Agent::Agent(asio::io_context& io_context) :
		io_context(io_context),
		socket(asio::ip::udp::socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 13))) {
	};

	void Agent::SetReceiverEndpoint(std::string ipString, std::string portString) {
		receiverIpString = ipString;
		receiverPortString = portString;

		ResolveEndpoint(receiverIpString, receiverPortString);
	}

	const asio::ip::udp::endpoint Agent::GetReceiverEndpoint() const {
		return receiverEndpoint;
	}

	void Agent::ResolveEndpoint(std::string ipString, std::string portString) {
		asio::ip::udp::resolver resolver(io_context);

		receiverEndpoint = *resolver.resolve(asio::ip::udp::v4(), ipString, portString).begin();
	}

	size_t Agent::SendPacket(Packet& p) {
		return SendPacketTo(p, receiverEndpoint);
	}

	size_t Agent::SendPacketTo(Packet& p, asio::ip::udp::endpoint endpoint) {
		std::cout << "Sending to: " << endpoint.address().to_string() << ":" << endpoint.port() << std::endl;
		return socket.send_to(asio::buffer(p.BuildPacketVector()), endpoint);
	}

	Packet Agent::ReceivePacket() {
		return ReceivePacketFrom(receiverEndpoint);
	}

	Packet Agent::ReceivePacketFrom(asio::ip::udp::endpoint& endpoint) {
		PACKET_BUF recv_buf;
		size_t len = socket.receive_from(asio::buffer(recv_buf), endpoint);
		Packet packet{ recv_buf[0], recv_buf[1] };

		std::vector<uint8_t> dataVector;

		for (int i = 0; i < recv_buf[2]; ++i) {
			dataVector.push_back(recv_buf[i + 3]);
		}
		packet.SetData(dataVector);
		return packet;
	}
}
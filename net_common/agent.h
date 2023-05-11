#pragma once
#include <boost/asio.hpp>
#include <string>
#include "common.h"

using namespace boost;

namespace net {
	class Agent {
	public:
		Agent(asio::io_context& io_context, std::string receiverIp, std::string receiverPort);
		Agent(asio::io_context& io_context);
		size_t SendPacket(Packet& p);
		size_t SendPacketTo(Packet& p, asio::ip::udp::endpoint endpoint);
		Packet ReceivePacket();
		Packet ReceivePacketFrom(asio::ip::udp::endpoint& endpoint);

		void SetReceiverEndpoint(std::string ipString, std::string portString);
		const asio::ip::udp::endpoint GetReceiverEndpoint() const;
	private:
		asio::io_context& io_context;
		asio::ip::udp::socket socket;
		asio::ip::udp::endpoint receiverEndpoint;
		std::string receiverIpString;
		std::string receiverPortString;

		void ResolveEndpoint(std::string ipString, std::string portString);
	};
}
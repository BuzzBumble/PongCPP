#pragma once
#include <boost/asio.hpp>
#include <string>
#include "packet.h"

using namespace boost;

namespace net {
	class Agent {
	public:
		Agent(asio::io_context& io_context);
		asio::ip::udp::endpoint ResolveEndpoint(std::string ipString);
		size_t SendPacket(Packet& p);
		size_t SendPacketVector(std::vector<uint8_t> packetVector);
	private:
		asio::io_context& io_context;
		asio::ip::udp::socket socket;
	};
}
#pragma once
#include <boost/asio.hpp>
#include <string>
#include "common.h"

using namespace boost;

namespace net {
	class Agent {
	public:
		Agent(asio::io_context& io_context, std::string serverIp, std::string serverPort);
		size_t SendPacket(Packet& p);
		Packet ReceivePacket();

		void SetServerEndpoint(std::string ipString, std::string portString);
	private:
		asio::io_context& io_context;
		asio::ip::udp::socket socket;
		asio::ip::udp::endpoint serverEndpoint;
		std::string serverIpString;
		std::string serverPortString;

		void ResolveEndpoint(std::string ipString, std::string portString);
	};
}
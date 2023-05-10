#include "agent.h"

namespace net {
	Agent::Agent(asio::io_context& io_context) :
		io_context(io_context),
		socket(asio::ip::udp::socket(io_context))
	{

	};

	asio::ip::udp::endpoint Agent::ResolveEndpoint(std::string ipString) {
		asio::ip::udp::resolver resolver(io_context);

		return *resolver.resolve(asio::ip::udp::v4(), ipString, "pong").begin();
	}

	size_t Agent::SendPacket(Packet& p) {
		return socket.send_to(asio::buffer(p.BuildPacketVector()), ResolveEndpoint("127.0.0.1"));
	}
}
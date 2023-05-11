#include "agent.h"

namespace net {
	Agent::Agent(asio::io_context& io_context, std::string serverIp, std::string serverPort) :
		io_context(io_context),
		socket(asio::ip::udp::socket(io_context)),
		serverIpString(serverIp),
		serverPortString(serverPort)
	{
		socket.open(asio::ip::udp::v4());
		ResolveEndpoint(serverIpString, serverPortString);
	};

	void Agent::SetServerEndpoint(std::string ipString, std::string portString) {
		serverIpString = ipString;
		serverPortString = portString;

		ResolveEndpoint(serverIpString, serverPortString);
	}

	void Agent::ResolveEndpoint(std::string ipString, std::string portString) {
		asio::ip::udp::resolver resolver(io_context);

		serverEndpoint = *resolver.resolve(asio::ip::udp::v4(), ipString, portString).begin();
	}

	size_t Agent::SendPacket(Packet& p) {
		return socket.send_to(asio::buffer(p.BuildPacketVector()), serverEndpoint);
	}

	Packet Agent::ReceivePacket() {
		PACKET_BUF recv_buf;
		size_t len = socket.receive_from(asio::buffer(recv_buf), serverEndpoint);
		Packet packet{ recv_buf[0], recv_buf[1] };
		
		std::vector<uint8_t> dataVector;

		for (int i = 0; i < recv_buf[2]; ++i) {
			dataVector.push_back(recv_buf[i + 3]);
		}
		packet.SetData(dataVector);
		return packet;
	}
}
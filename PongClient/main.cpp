#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "net_common/common.h"

using namespace boost;
using namespace boost::asio::ip;

int main() {
	try {
		std::string ipString = "127.0.0.1";
		std::string portString = "13";
		asio::io_context io_context;

		net::Agent agent(io_context, ipString, portString);

		net::Packet packet{ net::Packet::DEFAULT_PROTO_ID, net::Packet::TYPE_CONNREQ };

		std::vector<uint8_t> testVector = { 1, 2, 3, 4 };
		packet.SetData(testVector);

		for (;;) {
			std::string s;
			std::getline(std::cin, s);
			if (s == "stop") {
				break;
			}

			size_t sent = agent.SendPacket(packet);
			std::cout << "Sent " << sent << " bytes." << std::endl;
			net::Packet p = agent.ReceivePacket();

			std::cout << "Received " << p.GetTotalSize() << " bytes: ";

			std::vector<uint8_t> packetVector = p.BuildPacketVector();

			for (auto i : packetVector) {
				std::cout << static_cast<int>(i) << " ";
			}
			std::cout << std::endl;

		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::string s;
		std::getline(std::cin, s);
	}
	
	
	return 0;
}

//float gameHeight = SCREEN_HEIGHT - GAME_TOP;
//float midY = (gameHeight / 2.0f) - (Paddle::DEFAULT_DIMENSIONS.y / 2.0f) + GAME_TOP;
//Paddle p1 = Paddle{ 1, Paddle::DEFAULT_DIMENSIONS, Vector2{Paddle::DEFAULT_OFFSET, midY}, WHITE };
//Paddle p2 = Paddle{ 2, Paddle::DEFAULT_DIMENSIONS, Vector2{SCREEN_WIDTH - (Paddle::DEFAULT_OFFSET + Paddle::DEFAULT_DIMENSIONS.x), midY}, WHITE };
//Ball ball = Ball{ Ball::DEFAULT_RADIUS, RED, p1, p2 };

//GameManager gameManager = GameManager{ p1, p2, ball };
//gameManager.Start();
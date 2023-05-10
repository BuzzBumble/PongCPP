#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio::ip;

int main() {

	asio::io_context io_context;
	udp::resolver resolver(io_context);
	udp::endpoint endpoint = *resolver.resolve(udp::v4(), "127.0.0.1", "pong").begin();

	udp::socket socket(io_context);
	socket.open(udp::v4());

	std::vector<uint8_t> testVector{ 1, 2, 3, 4 };
	boost::array<uint8_t, 4> testArray{ 1, 2, 3, 4 };

	size_t sent = socket.send_to(asio::buffer(testArray), endpoint);

	std::cout << sent << std::endl;

	std::string s;
	std::getline(std::cin, s);
	
	return 0;
}

//float gameHeight = SCREEN_HEIGHT - GAME_TOP;
//float midY = (gameHeight / 2.0f) - (Paddle::DEFAULT_DIMENSIONS.y / 2.0f) + GAME_TOP;
//Paddle p1 = Paddle{ 1, Paddle::DEFAULT_DIMENSIONS, Vector2{Paddle::DEFAULT_OFFSET, midY}, WHITE };
//Paddle p2 = Paddle{ 2, Paddle::DEFAULT_DIMENSIONS, Vector2{SCREEN_WIDTH - (Paddle::DEFAULT_OFFSET + Paddle::DEFAULT_DIMENSIONS.x), midY}, WHITE };
//Ball ball = Ball{ Ball::DEFAULT_RADIUS, RED, p1, p2 };

//GameManager gameManager = GameManager{ p1, p2, ball };
//gameManager.Start();
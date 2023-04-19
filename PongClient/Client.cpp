#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio::ip;

int main() {
	asio::io_context io_context;

	udp::resolver resolver(io_context);
	udp::endpoint receiver_endpoint =
		*resolver.resolve(udp::v4(), "127.0.0.1:13", "daytime").begin();

	udp::socket socket(io_context);
	socket.open(udp::v4());
	boost::array<char, 1> send_buf = { {0} };
	socket.send_to(asio::buffer(send_buf), receiver_endpoint);

	boost::array<char, 128> recv_buf;
	udp::endpoint sender_endpoint;
	size_t len = socket.receive_from(
		asio::buffer(recv_buf), sender_endpoint);
	std::cout.write(recv_buf.data(), len);
	return 0;
}
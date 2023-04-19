#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio::ip;

int main() {
	asio::io_context io_context;
	udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));

	for (;;) {
		boost::array<char, 1> recv_buf;
		udp::endpoint remote_endpoint;
		socket.receive_from(asio::buffer(recv_buf), remote_endpoint);
		std::string message = "Hello from the server";
		socket.send_to(asio::buffer(message), remote_endpoint, 0);
	}
	return 0;
}
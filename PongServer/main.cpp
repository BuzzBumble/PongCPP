#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "Server.h"

using namespace boost;
using namespace boost::asio::ip;

int main() {
	asio::io_context io_context;
	net::Agent agent{ io_context };
	Server server{ agent };
	boost::array<uint8_t, 32> recv_buf;
	udp::endpoint remote_endpoint;

	for (;;) {
		try {
			server.ReceiveMessage();
			//boost::array<uint8_t, 32> send_buf = { 4, 2, 1, 5 };
			//size_t sent = socket.send_to(asio::buffer(send_buf), remote_endpoint);
			//std::cout << "Sent " << sent << " bytes." << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
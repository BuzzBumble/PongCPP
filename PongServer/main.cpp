#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio::ip;

int main() {
	asio::io_context io_context;
	udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));

	boost::array<uint8_t, 32> recv_buf;
	udp::endpoint remote_endpoint;

	for (;;) {
		try {
			size_t len = socket.receive_from(asio::buffer(recv_buf), remote_endpoint);
			std::cout << "From: " << remote_endpoint.address().to_string() << ":" << remote_endpoint.port() << ": ";
			for (int i = 0; i < len; i++) {
				std::cout << static_cast<int>(recv_buf[i]) << " ";
			}
			std::cout << std::endl;
			boost::array<uint8_t, 32> send_buf = { 4, 2, 1, 5 };
			size_t sent = socket.send_to(asio::buffer(send_buf), remote_endpoint);
			std::cout << "Sent " << sent << " bytes." << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
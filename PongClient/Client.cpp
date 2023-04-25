#include "Client.h"


Client::Client(asio::io_context& io_context) :
	io_context(io_context),
	socket(udp::socket(io_context)) {

	connectionState = Disconnected;
	sendBuf = array<char, 64>{};
	recvBuf = array<char, 64>{};
}

void Client::ResolveReceiverEndpoint() {
	udp::resolver resolver(io_context);

	receiverEndpoint = *resolver.resolve(udp::v4(), "127.0.0.1", "pong").begin();
}
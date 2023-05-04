#include "Client.h"

Client::Client(asio::io_context& io_context) :
	io_context(io_context),
	socket(udp::socket(io_context)) {

	connectionState = Disconnected;
}

void Client::ResolveReceiverEndpoint() {
	udp::resolver resolver(io_context);

	receiverEndpoint = *resolver.resolve(udp::v4(), "127.0.0.1", "pong").begin();
}

void Client::AttemptConnection() {
	SendToServer(Connection, boost::array<char, 3>{});
	boost::array<char, 4> buf;
	size_t len = WaitForMessage(asio::buffer(buf));
	if (senderEndpoint != receiverEndpoint) {
		return;
	}
	std::cout << buf.data() << std::endl;
}

size_t Client::SendToServer(MessageType msgType, array<char, 3> data) {
	array<char, 4> sendBuf;
	sendBuf[0] = msgType;
	for (int i = 0; i < data.size(); ++i) {
		sendBuf[i + 1] = data[i];
	}

	return socket.send_to(asio::buffer(sendBuf), receiverEndpoint);
}

size_t Client::WaitForMessage(boost::asio::mutable_buffer buf) {
	size_t len = socket.receive_from(asio::buffer(buf), senderEndpoint);
	return len;
}
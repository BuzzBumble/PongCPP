#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace boost;
using namespace boost::asio::ip;

class Client {
public:
	enum MessageType {
		Connection,
	};

	enum State {
		Disconnected,
		Connecting,
		Connected
	};
	
	Client(boost::asio::io_context& io_context);
	void ResolveReceiverEndpoint();
	size_t SendToServer(MessageType msgType, array<char, 3> sendBuf);
	void AttemptConnection();
	size_t WaitForMessage(boost::asio::mutable_buffer buf);

private:
	State connectionState;
	asio::io_context& io_context;
	udp::socket& socket;
	udp::endpoint receiverEndpoint;
	udp::endpoint senderEndpoint;

};
#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include "net_common/common.h"

using namespace boost;
using namespace boost::asio::ip;

class Client {
public:
	enum State {
		Disconnected,
		Connecting,
		Connected
	};
	
	Client(net::Agent& agent);
	size_t AttemptConnection();
	net::Packet ReceiveMessage();
	size_t SendToServer(net::Packet p);
private:
	State connectionState;
	net::Agent& agent;
};
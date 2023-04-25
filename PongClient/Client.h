#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost;
using namespace boost::asio::ip;

class Client {
public:
	enum State {
		Disconnected,
		Connecting,
		Connected
	};
	
	Client(boost::asio::io_context& io_context);

private:
	State connectionState;
	asio::io_context& io_context;
	udp::socket& socket;
	udp::endpoint receiverEndpoint;
	udp::endpoint senderEndpoint;
	array<char, 64> sendBuf;
	array<char, 64> recvBuf;

	void ResolveReceiverEndpoint();
};
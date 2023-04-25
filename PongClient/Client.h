#include <boost/asio.hpp>

using namespace boost::asio;

class Client {
public:
	enum State {
		Disconnected,
		Connecting,
		Connected
	};
private:
	State connectionState;
};
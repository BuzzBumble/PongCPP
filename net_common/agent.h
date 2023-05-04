#include <boost/asio.hpp>
#include <string>

using namespace boost;

namespace net {
	namespace udp {
		class Agent {
		public:
			Agent(asio::io_context& io_context);
			asio::ip::udp::endpoint ResolveEndpoint(std::string ipString);
		private:
			asio::io_context& io_context;
			asio::ip::udp::socket socket;
		};
	}
}
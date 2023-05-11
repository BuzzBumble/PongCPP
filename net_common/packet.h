#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <vector>

namespace net {
	class Packet {
	public:
		static const uint8_t DEFAULT_PROTO_ID;
		static const uint8_t TYPE_CONNREQ;
		static const uint8_t TYPE_CONNRES;

		Packet();
		void SetProtocolId(uint8_t id);
		void SetPacketType(uint8_t newType);
		void SetData(std::vector<uint8_t> newData);

		std::vector<uint8_t> BuildPacketVector();
	private:
		uint8_t protocol_id;
		uint8_t packet_type;
		std::vector<uint8_t> data;
	};
}
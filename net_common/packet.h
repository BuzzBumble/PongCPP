#pragma once
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <vector>

namespace net {
	class Packet {
	public:
		static const uint8_t DEFAULT_PROTO_ID;
		static const uint8_t TYPE_CONNREQ;
		static const uint8_t TYPE_CONNACCEPT;
		static const uint8_t TYPE_CONNREJECT;

		Packet();
		Packet(uint8_t protocolId, uint8_t packetType);
		void SetProtocolId(uint8_t id);
		void SetPacketType(uint8_t newType);
		void SetData(std::vector<uint8_t> newData);

		std::vector<uint8_t> BuildPacketVector();

		uint8_t GetProtocolId();
		uint8_t GetPacketType();
		std::vector<uint8_t> GetData();
		size_t GetTotalSize();
	private:
		uint8_t protocol_id;
		uint8_t packet_type;
		std::vector<uint8_t> data;
	};
}
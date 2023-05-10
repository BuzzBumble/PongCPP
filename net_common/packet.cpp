#include "packet.h"

namespace net {
	const uint8_t Packet::DEFAULT_PROTO_ID = 4;

	Packet::Packet() :
		protocol_id(0),
		packet_type(0),
		data(std::vector<uint8_t>{}) {};

	void Packet::SetProtocolId(uint8_t id) {
		protocol_id = id;
	}
	void Packet::SetPacketType(uint8_t newType) {
		packet_type = newType;
	}
	void Packet::SetData(std::vector<uint8_t> newData) {
		data = newData;
	}

	std::vector<uint8_t> Packet::BuildPacketVector() {
		std::vector<uint8_t> packetVector{ protocol_id, packet_type };
		packetVector.push_back(data.size());
		for (auto i : data) {
			packetVector.push_back(data.at(i));
		}
		return packetVector;
	}
}
#include "packet.h"

namespace net {
	const uint8_t Packet::DEFAULT_PROTO_ID = 4;
	const uint8_t Packet::TYPE_CONNREQ = 1;
	const uint8_t Packet::TYPE_CONNACCEPT = 2;
	const uint8_t Packet::TYPE_CONNREJECT = 3;

	Packet::Packet() :
		protocol_id(0),
		packet_type(0),
		data(std::vector<uint8_t>{}) {
	};

	Packet::Packet(uint8_t protocolId, uint8_t packetType) :
		protocol_id(protocolId),
		packet_type(packetType),
		data(std::vector<uint8_t>{}) {
	}

	uint8_t Packet::GetProtocolId() {
		return protocol_id;
	}
	uint8_t Packet::GetPacketType() {
		return packet_type;
	}

	std::vector<uint8_t> Packet::GetData() {
		return data;
	}

	size_t Packet::GetTotalSize() {
		return data.size() + 3;
	}

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
			packetVector.push_back(i);
		}
		return packetVector;
	}
}
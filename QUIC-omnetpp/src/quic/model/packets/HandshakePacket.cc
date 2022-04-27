#ifndef SRC_QUIC_MODEL_PACKETS_HALFPARSEDPACKET_H_
#define SRC_QUIC_MODEL_PACKETS_HALFPARSEDPACKET_H_
#include "PacketType.h"
#include "QuicPacket.h"
#include "LongHeaderPacket.h"
#include <string>
#include <iostream>
#include "../Version.h"
#include "HandshakePacket.h"


HandshakePacket::HandshakePacket(long destinationConnectionId, long sourceConnectionId, QuicPayload payload, long packetNumber, int srcAddress, int destAddress) :
LongHeaderPacket(PacketType::Handshake, destinationConnectionId, sourceConnectionId, packetNumber, payload, srcAddress, destAddress) {
    // TODO Auto-generated constructor stub
}

HandshakePacket::~HandshakePacket() {
    // TODO Auto-generated destructor stub
}


#endif /* SRC_QUIC_MODEL_PACKETS_HALFPARSEDPACKET_H_ */

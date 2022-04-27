#include "ShortHeaderOneRttPacket.h"
#include "PacketType.h"

ShortHeaderOneRttPacket::ShortHeaderOneRttPacket(long destinationConnectionId,  long packetNumber, QuicPayload payload) {
    this->destinationConnectionId = destinationConnectionId;
    this->packetNumber = packetNumber;
    this->quicPayload = payload;
    this->setKind(PacketType::ZeroRTTProtected);
}

ShortHeaderOneRttPacket::~ShortHeaderOneRttPacket() {}

ShortHeaderOneRttPacket::ShortHeaderOneRttPacket(){
    this->setKind(PacketType::ZeroRTTProtected);
}


long ShortHeaderOneRttPacket::getDestinationConnectionId() const
{
    return this->destinationConnectionId;
}

void ShortHeaderOneRttPacket::setDestinationConnectionId(long id)
{
    this->destinationConnectionId = id;
}

long ShortHeaderOneRttPacket::getPacketNumber() const
{
    return this->packetNumber;
}

void ShortHeaderOneRttPacket::setPacketNumber(long packetNumber)
{
    this->packetNumber = packetNumber;
}

QuicPayload ShortHeaderOneRttPacket::getPayload() const
{
    return this->quicPayload;
}

void ShortHeaderOneRttPacket::setPayload(QuicPayload payload)
{
    this->quicPayload = payload;
}

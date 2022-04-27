//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "LongHeaderPacket.h"
LongHeaderPacket::LongHeaderPacket(PacketType packetType, long destinationConnectionId, long sourceConnectionId, long packetNumber, QuicPayload payload,
        int srcAddress, int destAddress) : QuicPacket(srcAddress, destAddress) {
    this->destinationConnectionId = destinationConnectionId;
    this->sourceConnectionId = sourceConnectionId;
    this->packetNumber = packetNumber;
    this->packetType = packetType;
    this->quicPayload = payload;
}

LongHeaderPacket::~LongHeaderPacket() {
    // TODO Auto-generated destructor stub
}

LongHeaderPacket::LongHeaderPacket(){}

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

QuicPayload LongHeaderPacket::validateFrames(QuicPayload *payload) {
    for (auto const &i : payload->frames) {
        if(instanceof<CryptoFrame>(&i) ||
                instanceof<AckFrame>(&i) ||
                instanceof<PingFrame>(&i) ||
                instanceof<PaddingFrame>(&i) ||
                instanceof<ConnectionCloseFrame>(&i) ||
                instanceof<ApplicationCloseFrame>(&i)) {

        }
    }
}

PacketType LongHeaderPacket::getPacketType() const
{
    return this->packetType;
}

void LongHeaderPacket::setPacketType(PacketType packetType)
{
    this->packetType = packetType;
}

long LongHeaderPacket::getDestinationConnectionId() const
{
    return this->destinationConnectionId;
}

long LongHeaderPacket::getSourceConnectionId() const
{
    return this->sourceConnectionId;
}

void LongHeaderPacket::setDestinationConnectionId(long id)
{
    this->destinationConnectionId = id;
}

void LongHeaderPacket::setSourceConnectionId(long id)
{
    this->sourceConnectionId = id;
}

long LongHeaderPacket::getPacketNumber() const
{
    return this->packetNumber;
}

void LongHeaderPacket::setPacketNumber(long packetNumber)
{
    this->packetNumber = packetNumber;
}

Version LongHeaderPacket::getVersion() const
{
    return this->version;
}

void LongHeaderPacket::setVersion(Version version)
{
    this->version = version;
}

QuicPayload LongHeaderPacket::getPayload() const
{
    return this->quicPayload;
}

void LongHeaderPacket::setPayload(QuicPayload payload)
{
    this->quicPayload = payload;
}



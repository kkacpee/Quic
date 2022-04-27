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

#ifndef SRC_QUIC_LONGHEADERPACKET_H_
#define SRC_QUIC_LONGHEADERPACKET_H_
#include "QuicPayload.h"
#include "QuicPacket.h"
#include "PacketType.h"
#include "../Version.h"

#include "../frames/CryptoFrame.h"
#include "../frames/AckFrame.h"
#include "../frames/ApplicationCloseFrame.h"
#include "../frames/PaddingFrame.h"
#include "../frames/PingFrame.h"
#include "../frames/ConnectionCloseFrame.h"

class LongHeaderPacket : public QuicPacket {
public:
    LongHeaderPacket(PacketType packetType, long destinationConnectionId, long sourceConnectionId, long packetNumber, QuicPayload payload, int srcAddress, int destAddress);
    LongHeaderPacket();
    virtual ~LongHeaderPacket();
    PacketType getPacketType(char byte);
    QuicPayload validateFrames(QuicPayload *payload);
    long destinationConnectionId;
    long sourceConnectionId;
    PacketType packetType;
    long packetNumber;
    QuicPayload quicPayload;
    Version version;

    // getters/setters
    virtual PacketType getPacketType() const;
    virtual void setPacketType(PacketType packetType);
    virtual long getDestinationConnectionId() const;
    virtual void setDestinationConnectionId(long id);
    virtual long getSourceConnectionId() const;
    virtual void setSourceConnectionId(long id);
    virtual long getPacketNumber() const;
    virtual void setPacketNumber(long packetNumber);
    virtual Version getVersion() const;
    virtual void setVersion(Version version);
    virtual QuicPayload getPayload() const;
    virtual void setPayload(QuicPayload payload);

};

#endif /* SRC_QUIC_LONGHEADERPACKET_H_ */

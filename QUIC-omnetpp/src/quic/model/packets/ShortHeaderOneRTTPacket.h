#ifndef SRC_QUIC_SHORTHEADER_RTTPACKET_H_
#define SRC_QUIC_SHORTHEADER_RTTPACKET_H_

#include "QuicPayload.h"
#include "QuicPacket.h"

class ShortHeaderOneRttPacket : public QuicPacket {
protected:
    long destinationConnectionId;
    long packetNumber;
    QuicPayload quicPayload;

public:
    ShortHeaderOneRttPacket(long destinationConnectionId, long packetNumber, QuicPayload quicPayload);
    ShortHeaderOneRttPacket();
    virtual ~ShortHeaderOneRttPacket();

    //getters/setters
    long getDestinationConnectionId() const;
    void setDestinationConnectionId(long id);
    long getPacketNumber() const;
    void setPacketNumber(long packetNumber);
    QuicPayload getPayload() const;
    void setPayload(QuicPayload payload);

};

#endif

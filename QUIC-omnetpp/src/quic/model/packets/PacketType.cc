#include "PacketType.h"

PacketType getPacketType(char b) {
    if(b == 0x0) {
        return PacketType::Initial;
    } else if (b == 0x1) {
        return PacketType::ZeroRTTProtected;
    } else if (b == 0x2) {
        return PacketType::Handshake;
    } else if (b == 0x3) {
        return PacketType::Retry;
    } else {
        throw std::invalid_argument( "Unknown PacketType value" );
    }
}


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

#ifndef SRC_QUIC_MODEL_PACKETS_INITIALPACKET_H_
#define SRC_QUIC_MODEL_PACKETS_INITIALPACKET_H_
#include "LongHeaderPacket.h"
#include "QuicPayload.h"
#include "PacketType.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
class InitialPacket: public LongHeaderPacket {
public:
    //TODO https://github.com/protocol7/quincy/blob/74e49d8a84a77eada23283ed823b8bc7e7ce321e/quic/src/main/java/com/protocol7/quincy/protocol/packets/InitialPacket.java
    InitialPacket(long destinationConnectionId, long sourceConnectionId, QuicPayload payload, long packetNumber, int srcAddress, int destAddress);
    InitialPacket();
    virtual ~InitialPacket();
    InitialPacket* complete(char messageBytes[]);
    int sizeOfMessage(char message[]);
    int getSampleLength();
    void copyData(int sampleOffset, char *array, char *dstArray);
    char* decryptHeader(char* sample, char* pn);
    int parse(char bb[]);
};

#endif /* SRC_QUIC_MODEL_PACKETS_INITIALPACKET_H_ */

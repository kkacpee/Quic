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

#include "InitialPacket.h"
InitialPacket::InitialPacket(long destinationConnectionId, long sourceConnectionId, QuicPayload payload, long packetNumber, int srcAddress, int destAddress) :
LongHeaderPacket(PacketType::Initial, destinationConnectionId, sourceConnectionId, packetNumber, payload, srcAddress, destAddress) {
    // TODO Auto-generated constructor stub
}

InitialPacket::InitialPacket() {}

InitialPacket::~InitialPacket() {
    // TODO Auto-generated destructor stub
}

// char = 1 byte
InitialPacket* InitialPacket::complete(char messageBytes[]) {
    // get size of whole message
    int messageLength = sizeOfMessage(messageBytes);

    int pnOffset = 4;
    int sampleOffset = pnOffset + 4; // stala wartosc przesuniecia
    int sampleLength = getSampleLength();
    if( messageLength + 4 < sampleLength) {
        throw std::invalid_argument("Packet too short to sample");
    }
    char* sample = new char[sampleLength];
    copyData(sampleOffset,messageBytes, sample);
    char *pn = new char[4]; // get 4 bytes for PN. Might be too long, but we'll handle that below
    copyData(pnOffset, messageBytes, pn);
    try {
        char *decryptedHeader = decryptHeader(sample, pn);
        char decryptedFirstByte = decryptedHeader[0];
        int pnLen = (decryptedFirstByte & 0x3) + 1;
        char *pnBytes;
        copyData(1 + pnLen, decryptedHeader, pnBytes);
        int packetNumber = parse(pnBytes);
        int payload = messageLength - pnLen;
        QuicPayload *quicPayload = new QuicPayload();
        return new InitialPacket();

    } catch(...) {
        std::cout << "Error occured!";
    }



}

int InitialPacket::sizeOfMessage(char message[]) {
    return sizeof(message)/sizeof(message[0]);
}

int InitialPacket::getSampleLength() {
    return 16;
}

// copy x number of bytes from array to dstArray
void InitialPacket::copyData(int sampleOffset, char *array, char *dstArray) {
    std::strcat(array+sampleOffset, dstArray);
}

char* InitialPacket::decryptHeader(char* sample, char* pn) {
    return nullptr;
}

int InitialPacket::parse(char bb[]) {
    if((sizeof(bb)/sizeof(bb[0])) < 1 || (sizeof(bb)/sizeof(bb[0])) > 4) {
        throw std::invalid_argument("Invalid packet buffer length");
    }
    int number = 0;
    for (int i = 0; i < (sizeof(bb)/sizeof(bb[0])); i++) {
      number = number << 8 | (bb[i] & 0xFF);
    }
    return number;
}


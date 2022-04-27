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

#include "QuicPacket.h"

QuicPacket::QuicPacket(int srcAddress, int destAddress) {
    this->srcAddress = srcAddress;
    this->destAddress = destAddress;
    //this->frames = new std::list<QuicFrame>;
}

QuicPacket::~QuicPacket() {
    // TODO Auto-generated destructor stub
}

QuicPacket::QuicPacket() {}

void QuicPacket::setPayload(QuicPayload payload)
{
    this->quicPayload = payload;
}

void QuicPacket::addFrame(QuicFrame *frame) {
    this->frames.push_back(frame);

}

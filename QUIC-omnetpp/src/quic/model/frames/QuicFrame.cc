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

#include "QuicFrame.h"

FrameType QuicFrame::getFrameType(char b) {
    if(b == 0x00) {
        return FrameType::PADDING;
    } else if (b == 0x01) {
        return FrameType::PING;
    } else if (b == 0x02 || b == 0x03) {
        return FrameType::ACK; // 0x02-0x03
    } else if (b == 0x04) {
        return FrameType::RESET_STREAM;
    } else if (b == 0x05) {
        return FrameType::STOP_SENDING;
    } else if (b == 0x06) {
        return FrameType::CRYPTO;
    } else if (b == 0x07) {
        return FrameType::NEW_TOKEN;
    } else if (b == 0x08) {
        return FrameType::STREAM; // 0x08 - 0x0f
    } else if (b == 0x10) {
        return FrameType::MAX_DATA;
    } else if (b == 0x11) {
        return FrameType::MAX_STREAM_DATA;
    } else if (b == 0x12) {
        return FrameType::MAX_STREAMS; // 0x012-0x13
    } else if (b == 0x14) {
        return FrameType::DATA_BLOCKED;
    } else if (b == 0x15) {
        return FrameType::STREAM_DATA_BLOCKED;
    } else if (b == 0x16) {
        return FrameType::STREAMS_BLOCKED; // 0x16-0x17
    } else if (b == 0x18) {
        return FrameType::NEW_CONNECTION_ID;
    } else if (b == 0x19) {
        return FrameType::RETIRE_CONNECTION_ID;
    } else if (b == 0x1a) {
        return FrameType::PATH_CHALLENGE;
    } else if (b == FrameType::PATH_RESPONSE) {
        return FrameType::PATH_RESPONSE;
    } else if (b == 0x1c) {
        return FrameType::CONNECTION_CLOSE;
    } else if (b == 0x1d) {
        return FrameType::APPLICATION_CLOSE;
    } else if (b == 0x1e) {
        return FrameType::HANDSHAKE_DONE;
    } else {
        throw std::invalid_argument( "Unknown FrameType value" );
    }

}

QuicFrame::QuicFrame() {
    // TODO Auto-generated constructor stub

}

QuicFrame::~QuicFrame() {
    // TODO Auto-generated destructor stub
}

int QuicFrame::calculateLength() {
    return 0;
}


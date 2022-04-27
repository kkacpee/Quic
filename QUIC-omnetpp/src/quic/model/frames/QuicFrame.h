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

#ifndef SRC_QUIC_QUICFRAME_H_
#define SRC_QUIC_QUICFRAME_H_

#include <iostream>
#include <list>
#include <iterator>
enum FrameType {
    STREAM,
    PADDING,
    CRYPTO,
    ACK,
    STOP_SENDING,
    PATH_CHALLENGE,
    NEW_CONNECTION_ID,
    PING,
    RETIRE_CONNECTION_ID,
    RESET_STREAM,
    CONNECTION_CLOSE,
    APPLICATION_CLOSE,
    MAX_STREAM_DATA,
    MAX_DATA,
    MAX_STREAMS,
    STREAM_DATA_BLOCKED,
    DATA_BLOCKED,
    STREAMS_BLOCKED,
    NEW_TOKEN,
    HANDSHAKE_DONE,
    PATH_RESPONSE
};
class QuicFrame {
public:

    QuicFrame();
    virtual ~QuicFrame();
    FrameType getFrameType(char byte);
    virtual int calculateLength() = 0;
    virtual FrameType getFirstFrameType() = 0;


};

#endif /* SRC_QUIC_QUICFRAME_H_ */

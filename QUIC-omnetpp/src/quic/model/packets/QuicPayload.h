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

#ifndef SRC_QUIC_MODEL_PACKETS_QUICPAYLOAD_H_
#define SRC_QUIC_MODEL_PACKETS_QUICPAYLOAD_H_
#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "../frames/QuicFrame.h"
#include "../frames/CryptoFrame.h"
class QuicPayload {
public:
    std::list <QuicFrame*> frames;
    QuicPayload();
    virtual ~QuicPayload();
    void addFrame(QuicFrame *frame);
    int calculateLength();
    QuicPayload parse(char *bytes, int length, int pn);

};

#endif /* SRC_QUIC_MODEL_PACKETS_QUICPAYLOAD_H_ */

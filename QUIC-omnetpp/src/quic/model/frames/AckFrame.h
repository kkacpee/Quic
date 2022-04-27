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

#ifndef SRC_QUIC_MODEL_FRAMES_ACKFRAME_H_
#define SRC_QUIC_MODEL_FRAMES_ACKFRAME_H_

#include "QuicFrame.h"
#include <omnetpp.h>


class AckFrame : public QuicFrame {
protected:
    FrameType type;
    long num_Blocks;
    long largest_Acknowledged;
    long ack_Delay;
    ::omnetpp::opp_string ack_Block_Section;
private:
    void copy(const AckFrame& frame);
public:
    AckFrame();
    AckFrame(const AckFrame& frame);
    virtual ~AckFrame();
    int calculateLength();
    FrameType getFirstFrameType();

    // getters/setters
    virtual FrameType getType() const;
    virtual void setType(FrameType type);
    virtual long getNum_Blocks() const;
    virtual void setNum_Blocks(long num_Blocks);
    virtual long getLargest_Acknowledged() const;
    virtual void setLargest_Acknowledged(long largest_Acknowledged);
    virtual long getAck_Delay() const;
    virtual void setAck_Delay(long ack_Delay);
    virtual const char * getAck_Block_Section() const;
    virtual void setAck_Block_Section(const char * ack_Block_Section);
};

#endif /* SRC_QUIC_MODEL_FRAMES_ACKFRAME_H_ */

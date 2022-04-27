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

#ifndef SRC_QUIC_MODEL_FRAMES_PINGFRAME_H_
#define SRC_QUIC_MODEL_FRAMES_PINGFRAME_H_

#include "QuicFrame.h"

class PingFrame : public QuicFrame {
public:
    FrameType type;
    long num_Blocks;
    long largest_ping;
    long ping_Delay;
    //::omnetpp::opp_string ping_Block_Section;
    PingFrame();
    virtual ~PingFrame();
    int calculateLength();
    FrameType getFirstFrameType();
};

#endif /* SRC_QUIC_MODEL_FRAMES_PINGFRAME_H_ */

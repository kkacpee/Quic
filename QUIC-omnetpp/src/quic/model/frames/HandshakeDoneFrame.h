#include "QuicFrame.h"

class HandshakeDoneFrame : public QuicFrame {
protected:
    FrameType type;
    long num_Blocks;
    long largest_ping;
    long ping_Delay;
public:
    HandshakeDoneFrame();
    virtual ~HandshakeDoneFrame();
    int calculateLength();
    FrameType getFirstFrameType();
};

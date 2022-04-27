#include "HandshakeDoneFrame.h"

HandshakeDoneFrame::HandshakeDoneFrame() {
    this->type = FrameType::HANDSHAKE_DONE;
}

HandshakeDoneFrame::~HandshakeDoneFrame() {
    // TODO Auto-generated destructor stub
}

int HandshakeDoneFrame::calculateLength() {
    return 1;
}

FrameType HandshakeDoneFrame::getFirstFrameType() {
    return FrameType::HANDSHAKE_DONE;
}

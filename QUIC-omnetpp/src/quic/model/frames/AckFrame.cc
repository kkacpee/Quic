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

#include "AckFrame.h"

AckFrame::AckFrame()
{
    this->type = FrameType::ACK;
    this->num_Blocks = 0;
    this->largest_Acknowledged = 0;
    this->ack_Delay = 0;
}

AckFrame::AckFrame(const AckFrame& frame)
{
    copy(frame);
}

AckFrame::~AckFrame() {
}

void AckFrame::copy(const AckFrame& frame)
{
    this->type = frame.type;
    this->num_Blocks = frame.num_Blocks;
    this->largest_Acknowledged = frame.largest_Acknowledged;
    this->ack_Delay = frame.ack_Delay;
    this->ack_Block_Section = frame.ack_Block_Section;
}

FrameType AckFrame::getType() const
{
    return this->type;
}

void AckFrame::setType(FrameType type)
{
    this->type = type;
}

long AckFrame::getNum_Blocks() const
{
    return this->num_Blocks;
}

void AckFrame::setNum_Blocks(long num_Blocks)
{
    this->num_Blocks = num_Blocks;
}

long AckFrame::getLargest_Acknowledged() const
{
    return this->largest_Acknowledged;
}

void AckFrame::setLargest_Acknowledged(long largest_Acknowledged)
{
    this->largest_Acknowledged = largest_Acknowledged;
}

long AckFrame::getAck_Delay() const
{
    return this->ack_Delay;
}

void AckFrame::setAck_Delay(long ack_Delay)
{
    this->ack_Delay = ack_Delay;
}

const char* AckFrame::getAck_Block_Section() const
{
    return this->ack_Block_Section.c_str();
}

void AckFrame::setAck_Block_Section(const char * ack_Block_Section)
{
    this->ack_Block_Section = ack_Block_Section;
}

int AckFrame::calculateLength() {
    return 1; //TODO
}

FrameType AckFrame::getFirstFrameType() {
    return FrameType::ACK;
}


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

#include "NewToken.h"

NewToken::NewToken() {
    this->type = FrameType::NEW_TOKEN;
    if (type != 0x07) {
        throw std::invalid_argument("Unknown FrameType value");
    }
}

NewToken::~NewToken() {
    // TODO Auto-generated destructor stub
}



int NewToken::calculateLength() {
    return 1;
}

FrameType NewToken::getFirstFrameType() {
    return FrameType::NEW_TOKEN;
}


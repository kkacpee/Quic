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

#include "Finished.h"

Finished::Finished() {
    // TODO Auto-generated constructor stub

}

Finished::~Finished() {
    // TODO Auto-generated destructor stub
}

int Finished::calculateLength() {
    return 1; //TODO
}

FrameType Finished::getFirstFrameType() {
    return FrameType::FINISHED;
}

void Finished::setDefaultServer() {
    this->TLSHandshakeHeaderMessageLength = "000020";
    this->verifyData = "068fcb606aa1c8aa354d7b6064a3328cf376bcd9f3200e68ace3de2ee9fcaccb";

}

void Finished::setDefaultClient() {
    this->TLSHandshakeHeaderMessageLength = "000020";
    this->verifyData = "50ffb0c1a425c641891c983d126726026d3db28ea3510bdc2054fcd637edcacc";

}

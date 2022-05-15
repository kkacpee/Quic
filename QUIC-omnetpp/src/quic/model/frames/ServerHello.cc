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

#include "ServerHello.h"

ServerHello::ServerHello() {
    // TODO Auto-generated constructor stub

}

ServerHello::~ServerHello() {
    // TODO Auto-generated destructor stub
}

int ServerHello::calculateLength() {
    return 1; //TODO
}

FrameType ServerHello::getFirstFrameType() {
    return FrameType::SERVER_HELLO;
}

void ServerHello::setDefault() {

    this->TLSHandshakeHeaderMessageLength = "000056";
    this->serverRandom = "707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f";
    this->cipherSuite = "1301"; //TLS_AES_128_GCM_SHA256
    this->extensionsLength = "002e";
    this->extensionKeyShare = "00330024001d00209fd7ad6dcff4298dd3f96d5b1b2af910a0535b1488d7f8fabb349a982880b615";
    /*
     *  00 33 - assigned value for extension "Key Share"
     *  00 24 - 0x24 (36) bytes of "Key Share" extension data follows
     *  00 1d - assigned value for x25519 (key exchange via curve25519)
     *  00 20 - 0x20 (32) bytes of public key follows
     *  9f d7 ... b6 15 - public key from the step "Server Key Exchange Generation"
     */
}

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

#include "EncryptedExtensions.h"

EncryptedExtensions::EncryptedExtensions() {
    // TODO Auto-generated constructor stub

}

EncryptedExtensions::~EncryptedExtensions() {
    // TODO Auto-generated destructor stub
}

int EncryptedExtensions::calculateLength() {
    return 1; //TODO
}

FrameType EncryptedExtensions::getFirstFrameType() {
    return FrameType::ENCRYPTED_EXTENSIONS;
}

void EncryptedExtensions::setDefault() {
    this->TLSHandshakeHeaderMessageLength = "000056";
    this->extensionsLength = "0054";
    this->extensionALPN = "0010000b00090870696e672f312e30";
    /*
     *  00 10 - assigned value for extension "Application Layer Protocol Negotiation"
     *  00 0b - 0xB (11) bytes of "ALPN" extension data follows
     *  00 09 - 9 bytes of "ALPN" protocol data follows
     *  08 - 8 bytes of a protocol name follows
     *  70 69 ... 2e 30 - the string "ping/1.0"
     */
    this->extensionQUICTransportParameters = "003900410008000102030405060701048001d4c003048000fff70404805000000504800800000604800800000704800800000801020901020a01030b01190f05735f636964";
    /*
     *  initial_destination_connection_id: 0001020304050607
     *  max_idle_timeout: 120000ms (2 minutes)
     *  max_udp_payload_size: 65527
     *  initial_max_data: 5242880
     *  initial_max_stream_data_bidi_local: 524288
     *  initial_max_stream_data_bidi_remote: 524288
     *  initial_max_stream_data_uni: 524288
     *  initial_max_streams_bidi: 2
     *  initial_max_streams_uni: 2
     *  ack_delay_exponent: 3
     */
}

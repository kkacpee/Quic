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

#include "ClientHello.h"

ClientHello::ClientHello() {
    // TODO Auto-generated constructor stub

}

ClientHello::~ClientHello() {
    // TODO Auto-generated destructor stub
}

int ClientHello::calculateLength() {
    return 1; //TODO
}

FrameType ClientHello::getFirstFrameType() {
    return FrameType::CLIENT_HELLO;
}

//Set all parameters to values corresponding to https://quic.ulfheim.net/
void ClientHello::setDefault(){
    this->TLSHandshakeHeaderMessageLength = "0000ea";
    this->clientRandom = "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f";
    this->cipherSuites = "0006130113021303";
    /*
     *  00 06 - 6 bytes of cipher suite data
     *  13 01 - assigned value for TLS_AES_128_GCM_SHA256
     *  13 02 - assigned value for TLS_AES_256_GCM_SHA384
     *  13 03 - assigned value for TLS_CHACHA20_POLY1305_SHA256
     */
    this->extensionsLength = "00bb";
    this->extensionServerName = "0000001800160000136578616d706c652e756c666865696d2e6e6574";
    /*
     *  00 00 - assigned value for extension "server name"
     *  00 18 - 0x18 (24) bytes of "server name" extension data follows
     *  00 16 - 0x16 (22) bytes of first (and only) list entry follows
     *  00 - list entry is type 0x00 "DNS hostname"
     *  00 13 - 0x13 (19) bytes of hostname follows
     *  65 78 61 ... 6e 65 74 - "example.ulfheim.net"
     */
    this->extensionSupportedGroups = "000a00080006001d00170018";
    /*
     *  00 0a - assigned value for extension "supported groups"
     *  00 08 - 8 bytes of "supported group" extension data follows
     *  00 06 - 6 bytes of data are in the curves list
     *  00 1d - assigned value for the curve "x25519"
     *  00 17 - assigned value for the curve "secp256r1"
     *  00 18 - assigned value for the curve "secp384r1"
     */
    this->extensionALPN = "0010000b00090870696e672f312e30";
    /*
     *  00 10 - assigned value for extension "Application Layer Protocol Negotiation"
     *  00 0b - 0xB (11) bytes of "ALPN" extension data follows
     *  00 09 - 9 bytes of "ALPN" protocol data follows
     *  08 - 8 bytes of a protocol name follows
     *  70 69 ... 2e 30 - the string "ping/1.0"
     */
    this->extensionSignatureAlgorithms = "000d00140012040308040401050308050501080606010201";
    /*
     *  00 0d - assigned value for extension "Signature Algorithms"
     *  00 14 - 0x14 (20) bytes of "Signature Algorithms" extension data follows
     *  00 12 - 0x12 (18) bytes of data are in the following list of algorithms
     *  04 03 - assigned value for ECDSA-SECP256r1-SHA256
     *  08 04 - assigned value for RSA-PSS-RSAE-SHA256
     *  04 01 - assigned value for RSA-PKCS1-SHA256
     *  05 03 - assigned value for ECDSA-SECP384r1-SHA384
     *  08 05 - assigned value for RSA-PSS-RSAE-SHA384
     *  05 01 - assigned value for RSA-PKCS1-SHA384
     *  08 06 - assigned value for RSA-PSS-RSAE-SHA512
     *  06 01 - assigned value for RSA-PKCS1-SHA512
     *  02 01 - assigned value for RSA-PKCS1-SHA1
     */
    this->extensionKeyShare = "003300260024001d0020358072d6365880d1aeea329adf9121383851ed21a28e3b75e965d0d2cd166254";
    /*
     *  00 33 - assigned value for extension "Key Share"
     *  00 26 - 0x26 (38) bytes of "Key Share" extension data follows
     *  00 24 - 0x24 (36) bytes of key share data follows
     *  00 1d - assigned value for x25519 (key exchange via curve25519)
     *  00 20 - 0x20 (32) bytes of public key follows
     *  35 80 ... 62 54 - public key from the step "Client Key Exchange Generation"
     */
    this->extensionPSKKeyExchangeModes = "002d00020101";
    /*
     * 00 2d - assigned value for extension "PSK Key Exchange Modes"
     * 00 02 - 2 bytes of "PSK Key Exchange Modes" extension data follows
     * 01 - 1 bytes of exchange modes follow
     * 01 - assigned value for "PSK with (EC)DHE key establishment"
     */
    this->extensionQUICTransportParameters = "0039003103048000fff7040480a0000005048010000006048010000007048010000008010a09010a0a01030b01190f05635f636964";
    /*
     * max_udp_payload_size: 65527
     * initial_max_data: 10485760
     * initial_max_stream_data_bidi_local: 1048576
     * initial_max_stream_data_bidi_remote: 1048576
     * initial_max_stream_data_uni: 1048576
     * initial_max_streams_bidi: 10
     * initial_max_streams_uni: 10
     * ack_delay_exponent: 3
     * initial_source_connection_id: "c_cid"
     */
}


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

#ifndef SRC_QUIC_MODEL_FRAMES_CLIENT_HELLO_H_
#define SRC_QUIC_MODEL_FRAMES_CLIENT_HELLO_H_

#include "QuicFrame.h"

class ClientHello : public QuicFrame {
public:
    ClientHello();
    virtual ~ClientHello();
    int calculateLength();
    FrameType getFirstFrameType();
    void setPublicKey(std::string key);
    void setDefault();

protected:
    std::string TLSHandshakeHeaderMessageType = "01"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string clientVersion = "0303"; //This field is no longer used
    std::string clientRandom; //32 bytes of random data.
    std::string sessionID = "00"; //This is a legacy field and is not used in QUIC.
    std::string cipherSuites; //The client provides an ordered list of which cipher suites it will support for encryption. The list is in the order preferred by the client, with highest preference first.
    std::string compressionMethods = "0100"; //TLS 1.3 no longer allows compression, so this field is always a single entry with the "null" compression method
    std::string extensionsLength; ///How many bytes of data will the extensions take
    std::string extensionServerName; //The client has provided the name of the server it is contacting, also known as SNI (Server Name Indication).
    std::string extensionSupportedGroups; //Support for elliptic curve cryptography for different curve types.
    std::string extensionALPN; //Used by QUIC to negotiate supported protocols and versions between server and client.
    std::string extensionSignatureAlgorithms; //This extension indicates which signature algorithms the client supports.
    std::string extensionKeyShare; //The client sends one or more ephemeral public keys using algorithm(s) that it thinks the server will support.
    std::string extensionPSKKeyExchangeModes; //The client indicates the modes available for establishing keys from pre-shared keys (PSKs).
    std::string extensionSupportedVersions = "002b0003020304"; //The client indicates its support of TLS 1.3.
    std::string extensionQUICTransportParameters; //The client's configuration values for the QUIC connection.

};




#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

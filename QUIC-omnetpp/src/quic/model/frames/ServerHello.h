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

#ifndef SRC_QUIC_MODEL_FRAMES_SERVER_HELLO_H_
#define SRC_QUIC_MODEL_FRAMES_SERVER_HELLO_H_

#include "QuicFrame.h"

class ServerHello : public QuicFrame {
public:
    ServerHello();
    virtual ~ServerHello();
    int calculateLength();
    FrameType getFirstFrameType();
    void setPublicKey(std::string key);
    void setDefault();
protected:
    std::string TLSHandshakeHeaderMessageType = "02"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string serverVersion = "0303"; //This field is no longer used
    std::string serverRandom; //32 bytes of random data
    std::string sessionID = "00"; ////This is a legacy field and is not used in QUIC.
    std::string cipherSuite; //Cipher suite selected from the list of options given by the client.
    std::string compressionMethod = "00"; //TLS 1.3 no longer allows compression, so the only choice fot the server is null - no compression.
    std::string extensionsLength; //How many bytes of data will the extensions take (extensionKeyShare+extensionSupportedVersions)
    std::string extensionKeyShare; //The server sends a public key using the algorithm of the public key sent by the client.
    std::string extensionSupportedVersions = "002b00020304"; //Negotiated version.

};

#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

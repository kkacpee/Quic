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

#ifndef SRC_QUIC_MODEL_FRAMES_ENCRYPTED_EXTENSIONS_H_
#define SRC_QUIC_MODEL_FRAMES_ENCRYPTED_EXTENSIONS_H_

#include "QuicFrame.h"

class EncryptedExtensions : public QuicFrame {
public:
    EncryptedExtensions();
    virtual ~EncryptedExtensions();
    int calculateLength();
    FrameType getFirstFrameType();
    void setDefault();
protected:
    std::string TLSHandshakeHeaderMessageType = "08"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string extensionsLength; //How many bytes of data will the extensions take (extensionKeyShare+extensionSupportedVersions)
    std::string extensionALPN; //Used by QUIC to negotiate supported protocols and versions between server and client.
    std::string extensionQUICTransportParameters; //The server's configuration values for the QUIC connection.
};

#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

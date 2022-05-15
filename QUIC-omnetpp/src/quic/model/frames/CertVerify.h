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

#ifndef SRC_QUIC_MODEL_FRAMES_CERT_VERIFY_H_
#define SRC_QUIC_MODEL_FRAMES_CERT_VERIFY_H_

#include "QuicFrame.h"

class CertVerify : public QuicFrame {
public:
    CertVerify();
    virtual ~CertVerify();
    int calculateLength();
    FrameType getFirstFrameType();
    void setDefault();
protected:
    std::string TLSHandshakeHeaderMessageType = "0f"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string signatureAlgorithm; //The server indicates the signature type
    std::string signatureLength; //Signature length
    std::string signature; //Signed hash of the handshake messages using the certificate's private key.
};

#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

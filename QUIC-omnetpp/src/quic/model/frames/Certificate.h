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

#ifndef SRC_QUIC_MODEL_FRAMES_CERTIFICATE_H_
#define SRC_QUIC_MODEL_FRAMES_CERTIFICATE_H_

#include "QuicFrame.h"

class Certificate : public QuicFrame {
public:
    Certificate();
    virtual ~Certificate();
    int calculateLength();
    FrameType getFirstFrameType();
    void setDefault();
protected:
    std::string TLSHandshakeHeaderMessageType = "0b"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string requestContext = "00"; //This record is empty if this certificate was not sent in response to a Certificate Request.
    std::string certificatesLength; //How many bytes of data will all certificates take
    std::string firstCertificateLength; //How many bytes of data will the first certificate take
    std::string firstCertificate; //The certificate in ASN.1 DER encoding
    std::string certificateExtensions; //The server can provide extension data for the certificate.

};

#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

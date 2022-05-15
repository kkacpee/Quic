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

#ifndef SRC_QUIC_MODEL_FRAMES_FINISHED_H_
#define SRC_QUIC_MODEL_FRAMES_FINISHED_H_

#include "QuicFrame.h"

class Finished : public QuicFrame {
public:
    Finished();
    virtual ~Finished();
    int calculateLength();
    FrameType getFirstFrameType();
    void setDefaultClient();
    void setDefaultServer();
protected:
    std::string TLSHandshakeHeaderMessageType = "14"; //Message type.
    std::string TLSHandshakeHeaderMessageLength; //Message length.
    std::string verifyData; //The verify_data is built using the server_secret from the "Server Handshake Keys Calc" step
                            //and a SHA256 hash of every handshake record before this point (ClientHello to CertificateVerify).

};

#endif /* SRC_QUIC_MODEL_FRAMES_CRYPTOFRAME_H_ */

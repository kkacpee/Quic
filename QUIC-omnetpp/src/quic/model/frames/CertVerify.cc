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

#include "CertVerify.h"

CertVerify::CertVerify() {
    // TODO Auto-generated constructor stub

}

CertVerify::~CertVerify() {
    // TODO Auto-generated destructor stub
}

int CertVerify::calculateLength() {
    return 1; //TODO
}

FrameType CertVerify::getFirstFrameType() {
    return FrameType::CERT_VERIFY;
}

void CertVerify::setDefault(){
    this->TLSHandshakeHeaderMessageLength = "000104";
    this->signatureAlgorithm = "0804"; // "rsa_pss_rsae_sha256"
    this->signatureLength = "0100";
    this->signature = "0a99af32a9e406d725f9a9396de5af3756b7a8f6e4dad585abc3f87c6d1fc15f5f00aba8dca9d05c"
            "db51d3c935433656d88b7432005ee7e04803b2475744d7555cf3de489cc216a485a728b21890e87aa9415d19e6"
            "3a6a779b9cdbb128a804c428b827fa65dfcd952ace54461e8a234058988e7f264d7ab6a51a21c62979b7a679f4"
            "a08770856e926d371b2e89169aa190b803636bb10c0fb905983d2b500aad2683dfbe156eccf666de1a5ad45d77"
            "38d5e78bd17bc3e6d25f9ad4afba8f81de9f4d5572118e08551a4bb94b56a970e804c68267454b517fc8386c9b"
            "ae3a77cccb7f290f6e58fba126f05333a11f8ab0892e6e7a89585382d36eef2529cf5b7b";
}

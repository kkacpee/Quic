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

#include "Certificate.h"

Certificate::Certificate() {
    // TODO Auto-generated constructor stub

}

Certificate::~Certificate() {
    // TODO Auto-generated destructor stub
}

int Certificate::calculateLength() {
    return 1; //TODO
}

FrameType Certificate::getFirstFrameType() {
    return FrameType::CERTIFICATE;
}


void Certificate::setDefault() {
    this->TLSHandshakeHeaderMessageLength = "00032e";
    this->certificatesLength = "00032a";
    this->firstCertificateLength = "000325";
    this->firstCertificate = "3082032130820209a0030201020208155a92adc2048f90300d06092a864886f70d0"
            "1010b05003022310b300906035504061302555331133011060355040a130a4578616d706c65204341301"
            "e170d3138313030353031333831375a170d3139313030353031333831375a302b310b300906035504061"
            "3025553311c301a060355040313136578616d706c652e756c666865696d2e6e657430820122300d06092"
            "a864886f70d01010105000382010f003082010a0282010100c4803606bae7476b089404eca7b691043ff"
            "792bc19eefb7d74d7a80d001e7b4b3a4ae60fe8c071fc73e7024c0dbcf4bdd11d396bba70464a13e94af"
            "83df3e10959547bc955fb412da3765211e1f3dc776caa53376eca3aecbec3aab73b31d56cb6529c8098b"
            "cc9e02818e20bf7f8a03afd1704509ece79bd9f39f1ea69ec47972e830fb5ca95de95a1e60422d5eebe5"
            "27954a1e7bf8a86f6466d0d9f16951a4cf7a04692595c1352f2549e5afb4ebfd77a37950144e4c026874"
            "c653e407d7d23074401f484ffd08f7a1fa05210d1f4f0d5ce79702932e2cabe701fdfad6b4bb71101f44"
            "bad666a11130fe2ee829e4d029dc91cdd6716dbb9061886edc1ba94210203010001a3523050300e06035"
            "51d0f0101ff0404030205a0301d0603551d250416301406082b0601050507030206082b0601050507030"
            "1301f0603551d23041830168014894fde5bcc69e252cf3ea300dfb197b81de1c146300d06092a864886f"
            "70d01010b05000382010100591645a69a2e3779e4f6dd271aba1c0bfd6cd75599b5e7c36e533eff36590"
            "84324c9e7a504079d39e0d42987ffe3ebdd09c1cf1d914455870b571dd19bdf1d24f8bb9a11fe80fd592"
            "ba0398cde11e2651e618ce598fa96e5372eef3d248afde17463ebbfabb8e4d1ab502a54ec0064e92f781"
            "9660d3f27cf209e667fce5ae2e4ac99c7c93818f8b2510722dfed97f32e3e9349d4c66c9ea6396d74446"
            "2a06b42c6d5ba688eac3a017bddfc8e2cfcad27cb69d3ccdca280414465d3ae348ce0f34ab2fb9c61837"
            "1312b191041641c237f11a5d65c844f0404849938712b959ed685bc5c5dd645ed19909473402926dcb40"
            "e3469a15941e8e2cca84bb6084636a0";
    this->certificateExtensions = "0000";
}

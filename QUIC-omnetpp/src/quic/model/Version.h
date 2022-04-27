#ifndef SRC_QUIC_MODEL_PACKETS_VERSION_H_
#define SRC_QUIC_MODEL_PACKETS_VERSION_H_
#include <string>
#include <iostream>
#include <cstddef>

class Version {
    private:
        unsigned char version;
    public:
        //Version Draft29 = new Version('ff00001d');
        //Version NegotiationVer = new Version('00000000');
        //Version Final = new Version('00000001');


        Version read(unsigned char bb);
        //void write(ByteBuf bb);
        unsigned char asBytes();
        Version(unsigned char version);
        Version();

};

#endif /* SRC_QUIC_MODEL_PACKETS_VERSION_H_*/

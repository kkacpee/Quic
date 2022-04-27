#include "Version.h"

Version::Version() {
}

Version::Version(unsigned char version) {
    this->version = version;
}

/*void write(ByteBuf bb) {
    bb.writeBytes(version);
}*/

unsigned char Version::asBytes() {
    return this->version;
}

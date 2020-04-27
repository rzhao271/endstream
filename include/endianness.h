#ifndef RAYZZ_END_STREAM_ENDIANNESS_H_
#define RAYZZ_END_STREAM_ENDIANNESS_H_

#include <stdint.h>

namespace rayzz {
    namespace endstream {
        typedef enum class _Endianness {
            ES_LITTLE_ENDIAN,
            ES_BIG_ENDIAN
        } Endianness;
    }
}

#endif
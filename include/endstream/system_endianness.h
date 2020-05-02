#ifndef RAYZZ_END_STREAM_SYSTEM_ENDIANNESS_H_
#define RAYZZ_END_STREAM_SYSTEM_ENDIANNESS_H_

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class system_endianness {
        public:
            static endianness get_system_endianness();
            static bool is_system_endianness(endianness endianness);
        };
    }
}

#endif

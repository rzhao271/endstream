#ifndef RAYZZ_END_STREAM_ENDIANNESS_HELPER_H_
#define RAYZZ_END_STREAM_ENDIANNESS_HELPER_H_

#include <string.h>

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class EndiannessHelper {
        public:
            static Endianness get_system_endianness();
            static bool is_system_endianness(Endianness endianness);
            static void flip_buffer(char* buffer, size_t buffer_size);
        };
    }
}

#endif
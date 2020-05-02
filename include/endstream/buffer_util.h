#ifndef RAYZZ_END_STREAM_BUFFER_UTIL_H_
#define RAYZZ_END_STREAM_BUFFER_UTIL_H_

#include <string.h>

namespace rayzz {
    namespace endstream {
        class buffer_util {
        public:
            static void flip_buffer(char* buffer, size_t buffer_size);
        };
    }
}

#endif

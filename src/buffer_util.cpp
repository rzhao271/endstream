#include "buffer_util.h"

namespace rayzz {
    namespace endstream {
        void buffer_util::flip_buffer(char* buffer, size_t buffer_size) {
            for (size_t i = 0; i <= buffer_size / 2; i++) {
                char tmp = buffer[i];
                buffer[i] = buffer[buffer_size - i - 1];
                buffer[buffer_size - i - 1] = tmp;
            }
        }
    }
}
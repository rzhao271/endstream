#include "endianness_helper.h"

namespace rayzz {
    namespace endstream {
        Endianness EndiannessHelper::get_system_endianness() {
            // adapted from https://stackoverflow.com/a/1001328
            int32_t test_value = 1;
            char reinterpreted = *reinterpret_cast<char*>(&test_value);
            if (reinterpreted == 1) {
                return Endianness::ES_LITTLE_ENDIAN;
            } else {
                return Endianness::ES_BIG_ENDIAN;
            }
        }

        bool EndiannessHelper::is_system_endianness(Endianness endianness) {
            return endianness == get_system_endianness();
        }

        void EndiannessHelper::flip_buffer(char* buffer, size_t buffer_size) {
            for (size_t i = 0; i <= buffer_size / 2; i++) {
                char tmp = buffer[i];
                buffer[i] = buffer[buffer_size - i - 1];
                buffer[buffer_size - i - 1] = tmp;
            }
        }
    }
}
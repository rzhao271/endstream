#include "endstream/system_endianness.h"

#include <stdint.h>

namespace rayzz {
    namespace endstream {
        endianness system_endianness::get_system_endianness() {
            // adapted from https://stackoverflow.com/a/1001328
            int32_t test_value = 1;
            char reinterpreted = *reinterpret_cast<char*>(&test_value);
            if (reinterpreted == 1) {
                return endianness::ES_LITTLE_ENDIAN;
            } else {
                return endianness::ES_BIG_ENDIAN;
            }
        }

        bool system_endianness::is_system_endianness(endianness endianness) {
            return endianness == get_system_endianness();
        }
    }
}

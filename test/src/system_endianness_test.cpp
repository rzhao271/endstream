#include <gtest/gtest.h>

#include "endstream/system_endianness.h"

namespace rayzz {
    namespace endstream
    {
        TEST(SystemEndiannessTest, IsSystemEndianness) {
            endianness ness = system_endianness::get_system_endianness();
            ASSERT_TRUE(system_endianness::is_system_endianness(ness));
        }
    }
}
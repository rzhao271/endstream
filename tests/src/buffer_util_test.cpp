#include <gtest/gtest.h>

#include "endstream/buffer_util.h"

namespace rayzz {
    namespace endstream {
        TEST(BufferUtilTest, FlipZero) {
            char buffer[2];
            buffer[0] = 'a';
            buffer[1] = 'b';
            buffer_util::flip_buffer(buffer, 0);
            ASSERT_EQ(buffer[0], 'a');
            ASSERT_EQ(buffer[1], 'b');
        }

        TEST(BufferUtilTest, FlipOne) {
            char buffer[1];
            buffer[0] = 'a';
            buffer_util::flip_buffer(buffer, 1);
            ASSERT_EQ(buffer[0], 'a');
        }

        TEST(BufferUtilTest, FlipTwo) {
            char buffer[2];
            buffer[0] = 'a';
            buffer[1] = 'b';
            buffer_util::flip_buffer(buffer, 2);
            ASSERT_EQ(buffer[0], 'b');
            ASSERT_EQ(buffer[1], 'a');
        }

        TEST(BufferUtilTest, FlipTwoOfFour) {
            char buffer[4];
            buffer[0] = 'a';
            buffer[1] = 'b';
            buffer[2] = 'c';
            buffer[3] = 'd';
            buffer_util::flip_buffer(buffer, 2);
            ASSERT_EQ(buffer[0], 'b');
            ASSERT_EQ(buffer[1], 'a');
            ASSERT_EQ(buffer[2], 'c');
            ASSERT_EQ(buffer[3], 'd');
        }

        TEST(BufferUtilTest, FlipHundred) {
            const size_t len = 100;
            char buffer[len];
            for (size_t i = 0; i < len; i++) {
                buffer[i] = i;
            }
            buffer_util::flip_buffer(buffer, len);
            for (size_t i = 0; i < len; i++) {
                ASSERT_EQ(buffer[i], len - i - 1);
            }
        }

        TEST(BufferUtilTest, FlipHundredHeap) {
            const size_t len = 100;
            char* buffer = new char[len];
            for (size_t i = 0; i < len; i++) {
                buffer[i] = i;
            }
            buffer_util::flip_buffer(buffer, len);
            for (size_t i = 0; i < len; i++) {
                ASSERT_EQ(buffer[i], len - i - 1);
            }
            delete[] buffer;
        }
    }
}
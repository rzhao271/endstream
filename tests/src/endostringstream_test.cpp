#include <gtest/gtest.h>

#include "endstream/endostringstream.h"

namespace rayzz {
    namespace endstream {
        class EndOStringStreamFixture : public ::testing::Test {
        protected:
            std::ostringstream unwrapped_oss;
            endostringstream oss;

            void SetUp() override {
            };

            void TearDown() override {
            };
        };

        TEST_F(EndOStringStreamFixture, GetEndian) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(oss.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndOStringStreamFixture, SetEndian) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            oss.set_endianness(endianness::ES_LITTLE_ENDIAN);
            ASSERT_EQ(oss.get_endianness(), endianness::ES_LITTLE_ENDIAN);
            oss.set_endianness(endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(oss.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndOStringStreamFixture, FlipEndian) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            oss.flip_endianness();
            ASSERT_EQ(oss.get_endianness(), endianness::ES_BIG_ENDIAN);
            oss.flip_endianness();
            ASSERT_EQ(oss.get_endianness(), endianness::ES_LITTLE_ENDIAN);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianUInt8) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            uint8_t first = (uint8_t)0xFF;
            uint8_t second = (uint8_t)0xFE;
            oss << first << second;

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianUInt8) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            uint8_t first = (uint8_t)0xFF;
            uint8_t second = (uint8_t)0xFE;
            oss << first << second;

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianInt8) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            int8_t first = (int8_t)0xFF;
            int8_t second = (int8_t)0xFE;
            oss << first << second;

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianInt8) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            int8_t first = (int8_t)0xFF;
            int8_t second = (int8_t)0xFE;
            oss << first << second;

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianUInt16) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            uint16_t first = (uint16_t)0xFFFE;
            uint16_t second = (uint16_t)0xFDFC;
            oss << first << second;

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC 
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianUInt16) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            uint16_t first = (uint16_t)0xFFFE;
            uint16_t second = (uint16_t)0xFDFC;
            oss << first << second;

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFE, (char)0xFF, (char)0xFC, (char)0xFD
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianInt16) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            int16_t first = (int16_t)0xFFFE;
            int16_t second = (int16_t)0xFDFC;
            oss << first << second;

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC 
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianInt16) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            int16_t first = (int16_t)0xFFFE;
            int16_t second = (int16_t)0xFDFC;
            oss << first << second;

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFE, (char)0xFF, (char)0xFC, (char)0xFD
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianUInt32) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            uint32_t first = (uint32_t)0xFFFEFDFC;
            uint32_t second = (uint32_t)0xFBFAF9F8;
            oss << first << second;

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianUInt32) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            uint32_t first = (uint32_t)0xFFFEFDFC;
            uint32_t second = (uint32_t)0xFBFAF9F8;
            oss << first << second;

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianInt32) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            int32_t first = (int32_t)0xFFFEFDFC;
            int32_t second = (int32_t)0xFBFAF9F8;
            oss << first << second;

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianInt32) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            int32_t first = (int32_t)0xFFFEFDFC;
            int32_t second = (int32_t)0xFBFAF9F8;
            oss << first << second;

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianUInt64) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            uint64_t first = (uint64_t)0xFFFEFDFCFBFAF9F8;
            uint64_t second = (uint64_t)0xF7F6F5F4F3F2F1F0;
            oss << first << second;

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianUInt64) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            uint64_t first = (uint64_t)0xFFFEFDFCFBFAF9F8;
            uint64_t second = (uint64_t)0xF7F6F5F4F3F2F1F0;
            oss << first << second;

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF0, (char)0xF1, (char)0xF2, (char)0xF3,
                (char)0xF4, (char)0xF5, (char)0xF6, (char)0xF7,
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteBigEndianInt64) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            oss << first << second;

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteLittleEndianInt64) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            oss << first << second;

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF0, (char)0xF1, (char)0xF2, (char)0xF3,
                (char)0xF4, (char)0xF5, (char)0xF6, (char)0xF7,
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, WriteFlipInt64) {
            oss = endostringstream(std::move(unwrapped_oss), endianness::ES_LITTLE_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            oss << first;
            oss.flip_endianness();
            oss << second;

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            std::string buffer = oss.str();
            ASSERT_EQ(buffer.length(), num_bytes);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, num_bytes), 0);
        }

        TEST_F(EndOStringStreamFixture, SwapAndWriteChars) {
            endostringstream oss_first;
            endostringstream oss_second = endostringstream(std::move(unwrapped_oss), endianness::ES_BIG_ENDIAN);

            const size_t buffer_len = 3;
            swap(oss_first, oss_second);
            char buffer1[buffer_len] = {(char)0xFF, (char)0xFE, (char)0xFD};
            oss_first.write(buffer1, buffer_len);

            char buffer2[buffer_len] = {(char)0xFC, (char)0xFB, (char)0xFA};
            oss_second.swap(oss_first);
            oss_second.flip_endianness();
            oss_second.write(buffer2, buffer_len);

            char expected[2 * buffer_len] = { 
                (char)0xFF, (char)0xFE, (char)0xFD,
                (char)0xFC, (char)0xFB, (char)0xFA
            };
            std::string buffer = oss_second.str();
            ASSERT_EQ(buffer.length(), 2 * buffer_len);
            ASSERT_EQ(memcmp(buffer.c_str(), expected, 2 * buffer_len), 0);
        }
    }
}
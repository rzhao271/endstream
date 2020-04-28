#include <gtest/gtest.h>

#include "endofstream.h"

namespace rayzz {
    namespace endstream {
        class EndOfStreamFixture : public ::testing::Test {
            const char* filename = "endofstreamtest.out";
        protected:
            std::ofstream unwrapped_fout;
            endofstream fout;

            void SetUp() override {
                unwrapped_fout = std::ofstream(filename, std::ios::binary);
            };

            void TearDown() override {
                // fout is already closed during the test
                remove(filename);
            };

            void read_bytes(char* buffer, size_t num_bytes) {
                std::ifstream fin(filename, std::ios::binary);
                fin.read(buffer, num_bytes);
                fin.close();
            }
        };

        TEST_F(EndOfStreamFixture, GetEndian) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(fout.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndOfStreamFixture, SetEndian) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            fout.set_endianness(endianness::ES_LITTLE_ENDIAN);
            ASSERT_EQ(fout.get_endianness(), endianness::ES_LITTLE_ENDIAN);
            fout.set_endianness(endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(fout.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndOfStreamFixture, FlipEndian) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            fout.flip_endianness();
            ASSERT_EQ(fout.get_endianness(), endianness::ES_BIG_ENDIAN);
            fout.flip_endianness();
            ASSERT_EQ(fout.get_endianness(), endianness::ES_LITTLE_ENDIAN);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianUInt8) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            uint8_t first = (uint8_t)0xFF;
            uint8_t second = (uint8_t)0xFE;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianUInt8) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            uint8_t first = (uint8_t)0xFF;
            uint8_t second = (uint8_t)0xFE;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianInt8) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            int8_t first = (int8_t)0xFF;
            int8_t second = (int8_t)0xFE;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianInt8) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            int8_t first = (int8_t)0xFF;
            int8_t second = (int8_t)0xFE;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 2;
            char expected[num_bytes] = { (char)0xFF, (char)0xFE };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianUInt16) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            uint16_t first = (uint16_t)0xFFFE;
            uint16_t second = (uint16_t)0xFDFC;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC 
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianUInt16) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            uint16_t first = (uint16_t)0xFFFE;
            uint16_t second = (uint16_t)0xFDFC;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFE, (char)0xFF, (char)0xFC, (char)0xFD
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianInt16) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            int16_t first = (int16_t)0xFFFE;
            int16_t second = (int16_t)0xFDFC;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC 
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianInt16) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            int16_t first = (int16_t)0xFFFE;
            int16_t second = (int16_t)0xFDFC;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 4;
            char expected[num_bytes] = { 
                (char)0xFE, (char)0xFF, (char)0xFC, (char)0xFD
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianUInt32) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            uint32_t first = (uint32_t)0xFFFEFDFC;
            uint32_t second = (uint32_t)0xFBFAF9F8;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianUInt32) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            uint32_t first = (uint32_t)0xFFFEFDFC;
            uint32_t second = (uint32_t)0xFBFAF9F8;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianInt32) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            int32_t first = (int32_t)0xFFFEFDFC;
            int32_t second = (int32_t)0xFBFAF9F8;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianInt32) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            int32_t first = (int32_t)0xFFFEFDFC;
            int32_t second = (int32_t)0xFBFAF9F8;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 8;
            char expected[num_bytes] = { 
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianUInt64) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            uint64_t first = (uint64_t)0xFFFEFDFCFBFAF9F8;
            uint64_t second = (uint64_t)0xF7F6F5F4F3F2F1F0;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianUInt64) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            uint64_t first = (uint64_t)0xFFFEFDFCFBFAF9F8;
            uint64_t second = (uint64_t)0xF7F6F5F4F3F2F1F0;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF0, (char)0xF1, (char)0xF2, (char)0xF3,
                (char)0xF4, (char)0xF5, (char)0xF6, (char)0xF7,
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteBigEndianInt64) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteLittleEndianInt64) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            fout << first << second;
            fout.close();

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF0, (char)0xF1, (char)0xF2, (char)0xF3,
                (char)0xF4, (char)0xF5, (char)0xF6, (char)0xF7,
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, WriteFlipInt64) {
            fout = endofstream(std::move(unwrapped_fout), endianness::ES_LITTLE_ENDIAN);
            int64_t first = (int64_t)0xFFFEFDFCFBFAF9F8;
            int64_t second = (int64_t)0xF7F6F5F4F3F2F1F0;
            fout << first;
            fout.flip_endianness();
            fout << second;
            fout.close();

            const size_t num_bytes = 16;
            char expected[num_bytes] = { 
                (char)0xF8, (char)0xF9, (char)0xFA, (char)0xFB,
                (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF,
                (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0,
            };
            char buffer[num_bytes];
            read_bytes(buffer, num_bytes);
            ASSERT_EQ(memcmp(buffer, expected, num_bytes), 0);
        }

        TEST_F(EndOfStreamFixture, SwapAndWriteChars) {
            endofstream foutfirst;
            endofstream foutsecond = endofstream(std::move(unwrapped_fout), endianness::ES_BIG_ENDIAN);

            const size_t buffer_len = 3;
            swap(foutfirst, foutsecond);
            char buffer1[buffer_len] = {(char)0xFF, (char)0xFE, (char)0xFD};
            foutfirst.write(buffer1, buffer_len);

            char buffer2[buffer_len] = {(char)0xFC, (char)0xFB, (char)0xFA};
            foutsecond.swap(foutfirst);
            foutsecond.flip_endianness();
            foutsecond.write(buffer2, buffer_len);

            foutfirst.close();
            foutsecond.close();

            char expected[2 * buffer_len] = { 
                (char)0xFF, (char)0xFE, (char)0xFD,
                (char)0xFC, (char)0xFB, (char)0xFA
            };
            char buffer[2 * buffer_len];
            read_bytes(buffer, 2 * buffer_len);
            ASSERT_EQ(memcmp(buffer, expected, buffer_len), 0);
        }
    }
}
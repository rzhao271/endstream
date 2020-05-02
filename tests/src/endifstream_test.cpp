#include <gtest/gtest.h>

#include "endstream/endifstream.h"

namespace rayzz {
    namespace endstream {
        class EndIfStreamFixture : public ::testing::Test {
            const char* filename = "endifstreamtest.in";
        protected:
            std::ifstream unwrapped_fin;
            endifstream fin;

            void SetUp() override {
                std::ofstream tmp_fout(filename, std::ios::binary);
                const char buffer[16] = {
                    (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                    (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                    (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                    (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0
                };
                tmp_fout.write(buffer, 16);
                tmp_fout.close();

                unwrapped_fin.open(filename, std::ios::binary);
            };

            void TearDown() override {
                fin.close();
                remove(filename);
            };
        };

        TEST_F(EndIfStreamFixture, GetEndian) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(fin.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndIfStreamFixture, SetEndian) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            fin.set_endianness(endianness::ES_LITTLE_ENDIAN);
            ASSERT_EQ(fin.get_endianness(), endianness::ES_LITTLE_ENDIAN);
            fin.set_endianness(endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(fin.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndIfStreamFixture, FlipEndian) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            fin.flip_endianness();
            ASSERT_EQ(fin.get_endianness(), endianness::ES_BIG_ENDIAN);
            fin.flip_endianness();
            ASSERT_EQ(fin.get_endianness(), endianness::ES_LITTLE_ENDIAN);
        }

        TEST_F(EndIfStreamFixture, ReadUInt8) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            uint8_t first;
            uint8_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint8_t)0xFF);
            ASSERT_EQ(second, (uint8_t)0xFE);
            fin.seekg(0);
            fin.flip_endianness();
            fin >> first >> second;
            ASSERT_EQ(first, (uint8_t)0xFF);
            ASSERT_EQ(second, (uint8_t)0xFE);
        }

        TEST_F(EndIfStreamFixture, ReadInt8) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            int8_t first;
            int8_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int8_t)0xFF);
            ASSERT_EQ(second, (int8_t)0xFE);
            fin.seekg(0);
            fin.flip_endianness();
            fin >> first >> second;
            ASSERT_EQ(first, (int8_t)0xFF);
            ASSERT_EQ(second, (int8_t)0xFE);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianUInt16) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            uint16_t first;
            uint16_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint16_t)0xFFFE);
            ASSERT_EQ(second, (uint16_t)0xFDFC);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianUInt16) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            uint16_t first;
            uint16_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint16_t)0xFEFF);
            ASSERT_EQ(second, (uint16_t)0xFCFD);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianInt16) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            int16_t first;
            int16_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int16_t)0xFFFE);
            ASSERT_EQ(second, (int16_t)0xFDFC);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianInt16) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            int16_t first;
            int16_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int16_t)0xFEFF);
            ASSERT_EQ(second, (int16_t)0xFCFD);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianUInt32) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            uint32_t first;
            uint32_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint32_t)0xFFFEFDFC);
            ASSERT_EQ(second, (uint32_t)0xFBFAF9F8);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianUInt32) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            uint32_t first;
            uint32_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint32_t)0xFCFDFEFF);
            ASSERT_EQ(second, (uint32_t)0xF8F9FAFB);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianInt32) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            int32_t first;
            int32_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int32_t)0xFFFEFDFC);
            ASSERT_EQ(second, (int32_t)0xFBFAF9F8);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianInt32) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            int32_t first;
            int32_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int32_t)0xFCFDFEFF);
            ASSERT_EQ(second, (int32_t)0xF8F9FAFB);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianUInt64) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            uint64_t first;
            uint64_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint64_t)0xFFFEFDFCFBFAF9F8);
            ASSERT_EQ(second, (uint64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianUInt64) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            uint64_t first;
            uint64_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (uint64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (uint64_t)0xF0F1F2F3F4F5F6F7);
        }

        TEST_F(EndIfStreamFixture, ReadBigEndianInt64) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            int64_t first;
            int64_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int64_t)0xFFFEFDFCFBFAF9F8);
            ASSERT_EQ(second, (int64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIfStreamFixture, ReadLittleEndianInt64) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            int64_t first;
            int64_t second;
            fin >> first >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF0F1F2F3F4F5F6F7);
        }

        TEST_F(EndIfStreamFixture, ReadFlipInt64) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            int64_t first;
            int64_t second;
            fin >> first;
            fin.flip_endianness();
            fin >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIfStreamFixture, SwapAndReadChars) {
            endifstream finfirst;
            endifstream finsecond = endifstream(std::move(unwrapped_fin), endianness::ES_BIG_ENDIAN);
            swap(finfirst, finsecond);

            const size_t buffer_len = 3;
            char buffer[buffer_len];
            char expected1[buffer_len] = {(char)0xFF, (char)0xFE, (char)0xFD};
            finfirst.read(buffer, buffer_len);
            ASSERT_EQ(memcmp(buffer, expected1, buffer_len), 0);

            char expected2[buffer_len] = {(char)0xFC, (char)0xFB, (char)0xFA};
            finsecond.swap(finfirst);
            finsecond.read(buffer, buffer_len);
            ASSERT_EQ(memcmp(buffer, expected2, buffer_len), 0);
        }

        TEST_F(EndIfStreamFixture, MoveConstructor) {
            fin = endifstream(std::move(unwrapped_fin), endianness::ES_LITTLE_ENDIAN);
            endifstream finsecond(std::move(fin));
            int64_t first;
            int64_t second;
            finsecond >> first >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF0F1F2F3F4F5F6F7);
        }
    }
}

#include <gtest/gtest.h>

#include "endstream/endistringstream.h"

namespace rayzz {
    namespace endstream {
        class EndIStringStreamFixture : public ::testing::Test {
        protected:
            std::istringstream unwrapped_iss;
            endistringstream iss;

            void SetUp() override {
                const char buffer[16] = { 
                    (char)0xFF, (char)0xFE, (char)0xFD, (char)0xFC,
                    (char)0xFB, (char)0xFA, (char)0xF9, (char)0xF8,
                    (char)0xF7, (char)0xF6, (char)0xF5, (char)0xF4,
                    (char)0xF3, (char)0xF2, (char)0xF1, (char)0xF0
                };

                unwrapped_iss = std::istringstream(std::string(buffer));
            };

            void TearDown() override {
            };
        };

        TEST_F(EndIStringStreamFixture, GetEndian) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(iss.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndIStringStreamFixture, SetEndian) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            iss.set_endianness(endianness::ES_LITTLE_ENDIAN);
            ASSERT_EQ(iss.get_endianness(), endianness::ES_LITTLE_ENDIAN);
            iss.set_endianness(endianness::ES_BIG_ENDIAN);
            ASSERT_EQ(iss.get_endianness(), endianness::ES_BIG_ENDIAN);
        }

        TEST_F(EndIStringStreamFixture, FlipEndian) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            iss.flip_endianness();
            ASSERT_EQ(iss.get_endianness(), endianness::ES_BIG_ENDIAN);
            iss.flip_endianness();
            ASSERT_EQ(iss.get_endianness(), endianness::ES_LITTLE_ENDIAN);
        }

        TEST_F(EndIStringStreamFixture, ReadUInt8) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            uint8_t first;
            uint8_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint8_t)0xFF);
            ASSERT_EQ(second, (uint8_t)0xFE);
            iss.seekg(0);
            iss.flip_endianness();
            iss >> first >> second;
            ASSERT_EQ(first, (uint8_t)0xFF);
            ASSERT_EQ(second, (uint8_t)0xFE);
        }

        TEST_F(EndIStringStreamFixture, ReadInt8) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            int8_t first;
            int8_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int8_t)0xFF);
            ASSERT_EQ(second, (int8_t)0xFE);
            iss.seekg(0);
            iss.flip_endianness();
            iss >> first >> second;
            ASSERT_EQ(first, (int8_t)0xFF);
            ASSERT_EQ(second, (int8_t)0xFE);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianUInt16) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            uint16_t first;
            uint16_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint16_t)0xFFFE);
            ASSERT_EQ(second, (uint16_t)0xFDFC);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianUInt16) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            uint16_t first;
            uint16_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint16_t)0xFEFF);
            ASSERT_EQ(second, (uint16_t)0xFCFD);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianInt16) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            int16_t first;
            int16_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int16_t)0xFFFE);
            ASSERT_EQ(second, (int16_t)0xFDFC);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianInt16) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            int16_t first;
            int16_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int16_t)0xFEFF);
            ASSERT_EQ(second, (int16_t)0xFCFD);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianUInt32) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            uint32_t first;
            uint32_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint32_t)0xFFFEFDFC);
            ASSERT_EQ(second, (uint32_t)0xFBFAF9F8);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianUInt32) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            uint32_t first;
            uint32_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint32_t)0xFCFDFEFF);
            ASSERT_EQ(second, (uint32_t)0xF8F9FAFB);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianInt32) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            int32_t first;
            int32_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int32_t)0xFFFEFDFC);
            ASSERT_EQ(second, (int32_t)0xFBFAF9F8);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianInt32) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            int32_t first;
            int32_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int32_t)0xFCFDFEFF);
            ASSERT_EQ(second, (int32_t)0xF8F9FAFB);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianUInt64) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            uint64_t first;
            uint64_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint64_t)0xFFFEFDFCFBFAF9F8);
            ASSERT_EQ(second, (uint64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianUInt64) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            uint64_t first;
            uint64_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (uint64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (uint64_t)0xF0F1F2F3F4F5F6F7);
        }

        TEST_F(EndIStringStreamFixture, ReadBigEndianInt64) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            int64_t first;
            int64_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int64_t)0xFFFEFDFCFBFAF9F8);
            ASSERT_EQ(second, (int64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIStringStreamFixture, ReadLittleEndianInt64) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            int64_t first;
            int64_t second;
            iss >> first >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF0F1F2F3F4F5F6F7);
        }

        TEST_F(EndIStringStreamFixture, ReadFlipInt64) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            int64_t first;
            int64_t second;
            iss >> first;
            iss.flip_endianness();
            iss >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF7F6F5F4F3F2F1F0);
        }

        TEST_F(EndIStringStreamFixture, SwapAndReadChars) {
            endistringstream eiss_first;
            endistringstream eiss_second = endistringstream(std::move(unwrapped_iss), endianness::ES_BIG_ENDIAN);
            swap(eiss_first, eiss_second);

            const size_t buffer_len = 3;
            char buffer[buffer_len];
            char expected1[buffer_len] = {(char)0xFF, (char)0xFE, (char)0xFD};
            eiss_first.read(buffer, buffer_len);
            ASSERT_EQ(memcmp(buffer, expected1, buffer_len), 0);

            char expected2[buffer_len] = {(char)0xFC, (char)0xFB, (char)0xFA};
            eiss_second.swap(eiss_first);
            eiss_second.read(buffer, buffer_len);
            ASSERT_EQ(memcmp(buffer, expected2, buffer_len), 0);
        }

        TEST_F(EndIStringStreamFixture, MoveConstructor) {
            iss = endistringstream(std::move(unwrapped_iss), endianness::ES_LITTLE_ENDIAN);
            endistringstream iss_second(std::move(iss));
            int64_t first;
            int64_t second;
            iss_second >> first >> second;
            ASSERT_EQ(first, (int64_t)0xF8F9FAFBFCFDFEFF);
            ASSERT_EQ(second, (int64_t)0xF0F1F2F3F4F5F6F7);
        }
    }
}

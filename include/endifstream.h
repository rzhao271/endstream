#ifndef RAYZZ_END_STREAM_END_IFSTREAM_H_
#define RAYZZ_END_STREAM_END_IFSTREAM_H_

#include <fstream>
#include <memory>

#include "endianness.h"
#include "endistream.h"

namespace rayzz {
    namespace endstream {
        class endifstream : public endistream, public std::ifstream {
            struct impl;
            std::unique_ptr<impl> pImpl;

        public:
            endifstream(std::ifstream&& is, endianness ness);
            endifstream(const endifstream& other) = delete;
            endifstream(endifstream&& other) noexcept;

            endifstream& operator=(const endifstream& other) = delete;
            endifstream& operator=(endifstream&& other) noexcept;

            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            std::istream& read(int8_t& val) override;
            std::istream& read(int16_t& val) override;
            std::istream& read(int32_t& val) override;
            std::istream& read(int64_t& val) override;
            std::istream& read(uint8_t& val) override;
            std::istream& read(uint16_t& val) override;
            std::istream& read(uint32_t& val) override;
            std::istream& read(uint64_t& val) override;
            std::istream& operator>>(int8_t& val) override;
            std::istream& operator>>(int16_t& val) override;
            std::istream& operator>>(int32_t& val) override;
            std::istream& operator>>(int64_t& val) override;
            std::istream& operator>>(uint8_t& val) override;
            std::istream& operator>>(uint16_t& val) override;
            std::istream& operator>>(uint32_t& val) override;
            std::istream& operator>>(uint64_t& val) override;

            friend void swap(endifstream& first, endifstream& second) noexcept;
        };
    }
}

#endif
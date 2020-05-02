#ifndef RAYZZ_END_STREAM_END_IFSTREAM_H_
#define RAYZZ_END_STREAM_END_IFSTREAM_H_

#include <fstream>
#include <memory>

#include "endianness.h"
#include "endistream.h"

namespace rayzz {
    namespace endstream {
        class endifstream : public std::ifstream, public endistream {
            struct impl;
            std::unique_ptr<impl> pImpl;

        public:
            using std::ifstream::read;
            using std::ifstream::operator>>;

            endifstream();
            ~endifstream();
            endifstream(std::ifstream&& is, endianness ness);
            endifstream(const endifstream& other) = delete;
            endifstream(endifstream&& other) noexcept;

            endifstream& operator=(const endifstream& other) = delete;
            endifstream& operator=(endifstream&& other) noexcept;

            endianness get_endianness() const override;
            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            endifstream& read(int8_t& val) override;
            endifstream& read(int16_t& val) override;
            endifstream& read(int32_t& val) override;
            endifstream& read(int64_t& val) override;
            endifstream& read(uint8_t& val) override;
            endifstream& read(uint16_t& val) override;
            endifstream& read(uint32_t& val) override;
            endifstream& read(uint64_t& val) override;
            endifstream& operator>>(int8_t& val) override;
            endifstream& operator>>(int16_t& val) override;
            endifstream& operator>>(int32_t& val) override;
            endifstream& operator>>(int64_t& val) override;
            endifstream& operator>>(uint8_t& val) override;
            endifstream& operator>>(uint16_t& val) override;
            endifstream& operator>>(uint32_t& val) override;
            endifstream& operator>>(uint64_t& val) override;

            void swap(endifstream& rhs) noexcept;
            friend void swap(endifstream& first, endifstream& second) noexcept;
        };
    }
}

#endif

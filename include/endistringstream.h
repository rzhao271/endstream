#ifndef RAYZZ_END_STREAM_END_ISTRINGSTREAM_H_
#define RAYZZ_END_STREAM_END_ISTRINGSTREAM_H_

#include <sstream>
#include <memory>

#include "endianness.h"
#include "endistream.h"

namespace rayzz {
    namespace endstream {
        class endistringstream : public std::istringstream, public endistream {
            struct impl;
            std::unique_ptr<impl> pImpl;

        public:
            endistringstream(std::istringstream&& is, endianness endianness);
            endistringstream(const endistringstream& other) = delete;
            endistringstream(endistringstream&& other) noexcept;

            endistringstream& operator=(const endistringstream& other) = delete;
            endistringstream& operator=(endistringstream&& other) noexcept;

            void set_endianness(endianness endianness) override;
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

            friend void swap(endistringstream& first, endistringstream& second) noexcept;
        };
    }
}

#endif
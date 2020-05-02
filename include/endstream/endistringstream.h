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
            using std::istringstream::read;
            using std::istringstream::operator>>;

            endistringstream();
            ~endistringstream();
            endistringstream(std::istringstream&& is, endianness ness);
            endistringstream(const endistringstream& other) = delete;
            endistringstream(endistringstream&& other) noexcept;

            endistringstream& operator=(const endistringstream& other) = delete;
            endistringstream& operator=(endistringstream&& other) noexcept;

            endianness get_endianness() const override;
            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            endistringstream& read(int8_t& val) override;
            endistringstream& read(int16_t& val) override;
            endistringstream& read(int32_t& val) override;
            endistringstream& read(int64_t& val) override;
            endistringstream& read(uint8_t& val) override;
            endistringstream& read(uint16_t& val) override;
            endistringstream& read(uint32_t& val) override;
            endistringstream& read(uint64_t& val) override;
            endistringstream& operator>>(int8_t& val) override;
            endistringstream& operator>>(int16_t& val) override;
            endistringstream& operator>>(int32_t& val) override;
            endistringstream& operator>>(int64_t& val) override;
            endistringstream& operator>>(uint8_t& val) override;
            endistringstream& operator>>(uint16_t& val) override;
            endistringstream& operator>>(uint32_t& val) override;
            endistringstream& operator>>(uint64_t& val) override;

            void swap(endistringstream& rhs) noexcept;
            friend void swap(endistringstream& first, endistringstream& second) noexcept;
        };
    }
}

#endif

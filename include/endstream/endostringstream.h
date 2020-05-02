#ifndef RAYZZ_END_STREAM_END_OSTRINGSTREAM_H_
#define RAYZZ_END_STREAM_END_OSTRINGSTREAM_H_

#include <sstream>
#include <memory>

#include "endianness.h"
#include "endostream.h"

namespace rayzz {
    namespace endstream {
        class endostringstream : public std::ostringstream, public endostream {
            struct impl;
            std::unique_ptr<impl> pImpl;

        public:
            using std::ostringstream::write;
            using std::ostringstream::operator<<;

            endostringstream();
            ~endostringstream();
            endostringstream(std::ostringstream&& os, endianness ness);
            endostringstream(endostringstream& other) = delete;
            endostringstream(const endostringstream& other) = delete;
            endostringstream(endostringstream&& other) noexcept;

            endostringstream& operator=(const endostringstream& other) = delete;
            endostringstream& operator=(endostringstream&& other) noexcept;

            endianness get_endianness() const override;
            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            endostringstream& write(int8_t val) override;
            endostringstream& write(int16_t val) override;
            endostringstream& write(int32_t val) override;
            endostringstream& write(int64_t val) override;
            endostringstream& write(uint8_t val) override;
            endostringstream& write(uint16_t val) override;
            endostringstream& write(uint32_t val) override;
            endostringstream& write(uint64_t val) override;
            endostringstream& operator<<(int8_t val) override;
            endostringstream& operator<<(int16_t val) override;
            endostringstream& operator<<(int32_t val) override;
            endostringstream& operator<<(int64_t val) override;
            endostringstream& operator<<(uint8_t val) override;
            endostringstream& operator<<(uint16_t val) override;
            endostringstream& operator<<(uint32_t val) override;
            endostringstream& operator<<(uint64_t val) override;

            void swap(endostringstream& rhs) noexcept;
            friend void swap(endostringstream& first, endostringstream& second) noexcept;
        };
    }
}

#endif

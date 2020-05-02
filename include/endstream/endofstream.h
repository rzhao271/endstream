#ifndef RAYZZ_END_STREAM_END_OFSTREAM_H_
#define RAYZZ_END_STREAM_END_OFSTREAM_H_

#include <fstream>
#include <memory>

#include "endianness.h"
#include "endostream.h"

namespace rayzz {
    namespace endstream {
        class endofstream : public std::ofstream, public endostream {
            struct impl;
            std::unique_ptr<impl> pImpl;

        public:
            using std::ofstream::write;
            using std::ofstream::operator<<;

            endofstream();
            ~endofstream();
            endofstream(std::ofstream&& os, endianness ness);
            endofstream(endofstream& other) = delete;
            endofstream(const endofstream& other) = delete;
            endofstream(endofstream&& other) noexcept;

            endofstream& operator=(const endofstream& other) = delete;
            endofstream& operator=(endofstream&& other) noexcept;

            endianness get_endianness() const override;
            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            endofstream& write(int8_t val) override;
            endofstream& write(int16_t val) override;
            endofstream& write(int32_t val) override;
            endofstream& write(int64_t val) override;
            endofstream& write(uint8_t val) override;
            endofstream& write(uint16_t val) override;
            endofstream& write(uint32_t val) override;
            endofstream& write(uint64_t val) override;
            endofstream& operator<<(int8_t val) override;
            endofstream& operator<<(int16_t val) override;
            endofstream& operator<<(int32_t val) override;
            endofstream& operator<<(int64_t val) override;
            endofstream& operator<<(uint8_t val) override;
            endofstream& operator<<(uint16_t val) override;
            endofstream& operator<<(uint32_t val) override;
            endofstream& operator<<(uint64_t val) override;

            void swap(endofstream& rhs) noexcept;
            friend void swap(endofstream& first, endofstream& second) noexcept;
        };
    }
}

#endif

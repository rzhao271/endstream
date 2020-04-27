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
            endofstream(std::ofstream&& os, endianness ness);
            endofstream(endofstream& other) = delete;
            endofstream(const endofstream& other) = delete;
            endofstream(endofstream&& other) noexcept;

            endofstream& operator=(const endofstream& other) = delete;
            endofstream& operator=(endofstream&& other) noexcept;

            void set_endianness(endianness ness) override;
            void flip_endianness() override;

            std::ostream& write(int8_t val) override;
            std::ostream& write(int16_t val) override;
            std::ostream& write(int32_t val) override;
            std::ostream& write(int64_t val) override;
            std::ostream& write(uint8_t val) override;
            std::ostream& write(uint16_t val) override;
            std::ostream& write(uint32_t val) override;
            std::ostream& write(uint64_t val) override;
            std::ostream& operator<<(int8_t val) override;
            std::ostream& operator<<(int16_t val) override;
            std::ostream& operator<<(int32_t val) override;
            std::ostream& operator<<(int64_t val) override;
            std::ostream& operator<<(uint8_t val) override;
            std::ostream& operator<<(uint16_t val) override;
            std::ostream& operator<<(uint32_t val) override;
            std::ostream& operator<<(uint64_t val) override;

            friend void swap(endofstream& first, endofstream& second) noexcept;
        };
    }
}

#endif
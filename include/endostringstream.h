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
            endostringstream(std::ostringstream&& os, endianness ness);
            endostringstream(endostringstream& other) = delete;
            endostringstream(const endostringstream& other) = delete;
            endostringstream(endostringstream&& other) noexcept;

            endostringstream& operator=(const endostringstream& other) = delete;
            endostringstream& operator=(endostringstream&& other) noexcept;

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

            friend void swap(endostringstream& first, endostringstream& second) noexcept;
        };
    }
}

#endif
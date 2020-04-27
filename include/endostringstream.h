#ifndef RAYZZ_END_STREAM_END_OSTRINGSTREAM_H_
#define RAYZZ_END_STREAM_END_OSTRINGSTREAM_H_

#include <sstream>
#include <memory>

#include <stdint.h>

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class EndOutputStringStream : std::ostringstream {
            struct EndOutputStringStreamImpl;
            std::unique_ptr<EndOutputStringStreamImpl> pImpl;

        public:
            EndOutputStringStream(std::ostringstream& os, Endianness endianness);
            EndOutputStringStream& write(int8_t val);
            EndOutputStringStream& write(int16_t val);
            EndOutputStringStream& write(int32_t val);
            EndOutputStringStream& write(int64_t val);
            EndOutputStringStream& write(uint8_t val);
            EndOutputStringStream& write(uint16_t val);
            EndOutputStringStream& write(uint32_t val);
            EndOutputStringStream& write(uint64_t val);
            EndOutputStringStream& operator<<(int8_t val);
            EndOutputStringStream& operator<<(int16_t val);
            EndOutputStringStream& operator<<(int32_t val);
            EndOutputStringStream& operator<<(int64_t val);
            EndOutputStringStream& operator<<(uint8_t val);
            EndOutputStringStream& operator<<(uint16_t val);
            EndOutputStringStream& operator<<(uint32_t val);
            EndOutputStringStream& operator<<(uint64_t val);
        };
    }
}

#endif
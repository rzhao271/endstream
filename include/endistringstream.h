#ifndef RAYZZ_END_STREAM_END_ISTRINGSTREAM_H_
#define RAYZZ_END_STREAM_END_ISTRINGSTREAM_H_

#include <sstream>
#include <memory>

#include <stdint.h>

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class EndInputStringStream : std::istringstream {
            struct EndInputStringStreamImpl;
            std::unique_ptr<EndInputStringStreamImpl> pImpl;

        public:
            EndInputStringStream(std::istringstream& is, Endianness endianness);
            EndInputStringStream& read(int8_t& val);
            EndInputStringStream& read(int16_t& val);
            EndInputStringStream& read(int32_t& val);
            EndInputStringStream& read(int64_t& val);
            EndInputStringStream& read(uint8_t& val);
            EndInputStringStream& read(uint16_t& val);
            EndInputStringStream& read(uint32_t& val);
            EndInputStringStream& read(uint64_t& val);
            EndInputStringStream& operator>>(int8_t& val);
            EndInputStringStream& operator>>(int16_t& val);
            EndInputStringStream& operator>>(int32_t& val);
            EndInputStringStream& operator>>(int64_t& val);
            EndInputStringStream& operator>>(uint8_t& val);
            EndInputStringStream& operator>>(uint16_t& val);
            EndInputStringStream& operator>>(uint32_t& val);
            EndInputStringStream& operator>>(uint64_t& val);
        };
    }
}

#endif
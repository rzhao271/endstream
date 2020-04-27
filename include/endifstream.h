#ifndef RAYZZ_END_STREAM_END_IFSTREAM_H_
#define RAYZZ_END_STREAM_END_IFSTREAM_H_

#include <fstream>
#include <memory>

#include <stdint.h>

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class EndInputFileStream : public std::ifstream {
            struct EndInputFileStreamImpl;
            std::unique_ptr<EndInputFileStreamImpl> pImpl;

        public:
            EndInputFileStream(std::ifstream& is, Endianness endianness);
            EndInputFileStream& read(int8_t& val);
            EndInputFileStream& read(int16_t& val);
            EndInputFileStream& read(int32_t& val);
            EndInputFileStream& read(int64_t& val);
            EndInputFileStream& read(uint8_t& val);
            EndInputFileStream& read(uint16_t& val);
            EndInputFileStream& read(uint32_t& val);
            EndInputFileStream& read(uint64_t& val);
            EndInputFileStream& operator>>(int8_t& val);
            EndInputFileStream& operator>>(int16_t& val);
            EndInputFileStream& operator>>(int32_t& val);
            EndInputFileStream& operator>>(int64_t& val);
            EndInputFileStream& operator>>(uint8_t& val);
            EndInputFileStream& operator>>(uint16_t& val);
            EndInputFileStream& operator>>(uint32_t& val);
            EndInputFileStream& operator>>(uint64_t& val);
        };
    }
}

#endif
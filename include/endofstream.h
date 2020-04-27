#ifndef RAYZZ_END_STREAM_END_OFSTREAM_H_
#define RAYZZ_END_STREAM_END_OFSTREAM_H_

#include <fstream>
#include <memory>

#include <stdint.h>

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class EndOutputFileStream : std::ofstream {
            struct EndOutputFileStreamImpl;
            std::unique_ptr<EndOutputFileStreamImpl> pImpl;

        public:
            EndOutputFileStream(std::ofstream& os, Endianness endianness);
            EndOutputFileStream& write(int8_t val);
            EndOutputFileStream& write(int16_t val);
            EndOutputFileStream& write(int32_t val);
            EndOutputFileStream& write(int64_t val);
            EndOutputFileStream& write(uint8_t val);
            EndOutputFileStream& write(uint16_t val);
            EndOutputFileStream& write(uint32_t val);
            EndOutputFileStream& write(uint64_t val);
            EndOutputFileStream& operator<<(int8_t val);
            EndOutputFileStream& operator<<(int16_t val);
            EndOutputFileStream& operator<<(int32_t val);
            EndOutputFileStream& operator<<(int64_t val);
            EndOutputFileStream& operator<<(uint8_t val);
            EndOutputFileStream& operator<<(uint16_t val);
            EndOutputFileStream& operator<<(uint32_t val);
            EndOutputFileStream& operator<<(uint64_t val);
        };
    }
}

#endif
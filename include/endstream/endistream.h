#ifndef RAYZZ_END_STREAM_END_ISTREAM_H_
#define RAYZZ_END_STREAM_END_ISTREAM_H_

#include <istream>

#include "endstream.h"

namespace rayzz {
    namespace endstream {
        class endistream : public endstream {
        public:
            virtual std::istream& read(int8_t& val) = 0;
            virtual std::istream& read(int16_t& val) = 0;
            virtual std::istream& read(int32_t& val) = 0;
            virtual std::istream& read(int64_t& val) = 0;
            virtual std::istream& read(uint8_t& val) = 0;
            virtual std::istream& read(uint16_t& val) = 0;
            virtual std::istream& read(uint32_t& val) = 0;
            virtual std::istream& read(uint64_t& val) = 0;
            virtual std::istream& operator>>(int8_t& val) = 0;
            virtual std::istream& operator>>(int16_t& val) = 0;
            virtual std::istream& operator>>(int32_t& val) = 0;
            virtual std::istream& operator>>(int64_t& val) = 0;
            virtual std::istream& operator>>(uint8_t& val) = 0;
            virtual std::istream& operator>>(uint16_t& val) = 0;
            virtual std::istream& operator>>(uint32_t& val) = 0;
            virtual std::istream& operator>>(uint64_t& val) = 0;
        };
    }
}

#endif

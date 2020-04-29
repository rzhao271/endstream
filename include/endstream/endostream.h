#ifndef RAYZZ_END_STREAM_END_OSTREAM_H_
#define RAYZZ_END_STREAM_END_OSTREAM_H_

#include <ostream>

#include "endstream.h"

namespace rayzz {
    namespace endstream {
        class endostream : public endstream {
        public:
            virtual std::ostream& write(int8_t val) = 0;
            virtual std::ostream& write(int16_t val) = 0;
            virtual std::ostream& write(int32_t val) = 0;
            virtual std::ostream& write(int64_t val) = 0;
            virtual std::ostream& write(uint8_t val) = 0;
            virtual std::ostream& write(uint16_t val) = 0;
            virtual std::ostream& write(uint32_t val) = 0;
            virtual std::ostream& write(uint64_t val) = 0;
            virtual std::ostream& operator<<(int8_t val) = 0;
            virtual std::ostream& operator<<(int16_t val) = 0;
            virtual std::ostream& operator<<(int32_t val) = 0;
            virtual std::ostream& operator<<(int64_t val) = 0;
            virtual std::ostream& operator<<(uint8_t val) = 0;
            virtual std::ostream& operator<<(uint16_t val) = 0;
            virtual std::ostream& operator<<(uint32_t val) = 0;
            virtual std::ostream& operator<<(uint64_t val) = 0;
        };
    }
}

#endif
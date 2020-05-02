#ifndef RAYZZ_END_STREAM_END_STREAM_H_
#define RAYZZ_END_STREAM_END_STREAM_H_

#include "endianness.h"

namespace rayzz {
    namespace endstream {
        class endstream {
        public:
            virtual endianness get_endianness() const = 0;
            virtual void set_endianness(endianness endianness) = 0;
            virtual void flip_endianness() = 0;
        };
    }
}

#endif

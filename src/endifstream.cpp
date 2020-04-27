#include "buffer_util.h"
#include "endifstream.h"
#include "system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::ifstream super;

        struct endifstream::impl {
            endianness ness;
            std::ifstream* parent;

            template<typename T>
            T parse() {
                size_t buffer_size = sizeof(T);
                char* buffer = new char[buffer_size];
                parent->read(buffer, buffer_size);
                if (!system_endianness::is_system_endianness(ness)) {
                    buffer_util::flip_buffer(buffer, buffer_size);
                }
                T val = *reinterpret_cast<T*>(buffer);
                delete[] buffer;
                return val;
            }
        };

        endifstream::endifstream(std::ifstream&& is, endianness ness) :
            super(std::move(is)) {
            pImpl = std::make_unique<impl>();
            pImpl->ness = ness;
            pImpl->parent = this;
        }

        void swap(endifstream& first, endifstream& second) noexcept {
            using std::swap;
            swap((std::ifstream&)first, (std::ifstream&)second);
            swap(first.pImpl, second.pImpl);
        }

        endifstream::endifstream(endifstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
        }

        endifstream& endifstream::operator=(endifstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
            return *this;
        }

        void endifstream::set_endianness(endianness ness) {
            pImpl->ness = ness;
        }

        void endifstream::flip_endianness() {
            pImpl->ness = (pImpl->ness == endianness::ES_BIG_ENDIAN) ?
                endianness::ES_LITTLE_ENDIAN :
                endianness::ES_BIG_ENDIAN;
        }

        std::istream& endifstream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        std::istream& endifstream::read(int16_t& val) {
            val = pImpl->parse<int16_t>();
            return *this;
        }

        std::istream& endifstream::read(int32_t& val) {
            val = pImpl->parse<int32_t>();
            return *this;
        }

        std::istream& endifstream::read(int64_t& val) {
            val = pImpl->parse<int64_t>();
            return *this;
        }

        std::istream& endifstream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        std::istream& endifstream::read(uint16_t& val) {
            val = pImpl->parse<uint16_t>();
            return *this;
        }

        std::istream& endifstream::read(uint32_t& val) {
            val = pImpl->parse<uint32_t>();
            return *this;
        }
        
        std::istream& endifstream::read(uint64_t& val) {
            val = pImpl->parse<uint64_t>();
            return *this;
        }

        std::istream& endifstream::operator>>(int8_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(int16_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(int32_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(int64_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(uint8_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(uint16_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(uint32_t& val) {
            return read(val);
        }

        std::istream& endifstream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}
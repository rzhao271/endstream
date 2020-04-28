#include "buffer_util.h"
#include "endistringstream.h"
#include "system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::istringstream super;

        struct endistringstream::impl {
            endianness ness;
            std::istringstream *parent;

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

        endistringstream::endistringstream() = default;
        endistringstream::~endistringstream() = default;

        endistringstream::endistringstream(
            std::istringstream&& is, 
            endianness ness) : super(std::move(is)) {
            pImpl = std::make_unique<impl>();
            pImpl->ness = ness;
            pImpl->parent = this;
        }

        void swap(endistringstream& first, endistringstream& second) noexcept {
            using std::swap;
            swap((std::istringstream&)first, (std::istringstream&)second);
            swap(first.pImpl, second.pImpl);
        }

        endistringstream::endistringstream(endistringstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
        }

        endistringstream& endistringstream::operator=(endistringstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
            return *this;
        }

        endianness endistringstream::get_endianness() const {
            return pImpl->ness;
        }

        void endistringstream::set_endianness(endianness ness) {
            pImpl->ness = ness;
        }

        void endistringstream::flip_endianness() {
            pImpl->ness = (pImpl->ness == endianness::ES_BIG_ENDIAN) ?
                endianness::ES_LITTLE_ENDIAN :
                endianness::ES_BIG_ENDIAN;
        }

        std::istream& endistringstream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        std::istream& endistringstream::read(int16_t& val) {
            val = pImpl->parse<int16_t>();
            return *this;
        }

        std::istream& endistringstream::read(int32_t& val) {
            val = pImpl->parse<int32_t>();
            return *this;
        }

        std::istream& endistringstream::read(int64_t& val) {
            val = pImpl->parse<int64_t>();
            return *this;
        }

        std::istream& endistringstream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        std::istream& endistringstream::read(uint16_t& val) {
            val = pImpl->parse<uint16_t>();
            return *this;
        }

        std::istream& endistringstream::read(uint32_t& val) {
            val = pImpl->parse<uint32_t>();
            return *this;
        }
        
        std::istream& endistringstream::read(uint64_t& val) {
            val = pImpl->parse<uint64_t>();
            return *this;
        }

        std::istream& endistringstream::operator>>(int8_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(int16_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(int32_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(int64_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(uint8_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(uint16_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(uint32_t& val) {
            return read(val);
        }

        std::istream& endistringstream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}
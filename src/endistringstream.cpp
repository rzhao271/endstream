#include "endstream/buffer_util.h"
#include "endstream/endistringstream.h"
#include "endstream/system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::istringstream super;

        struct endistringstream::impl {
            endianness ness;

            impl(endianness ness) {
                this->ness = ness;
            }

            template<typename T>
            void parse(endistringstream* parent, T& val) {
                size_t buffer_size = sizeof(T);
                char* buffer = new char[buffer_size];
                parent->std::istringstream::read(buffer, buffer_size);
                if (!system_endianness::is_system_endianness(ness)) {
                    buffer_util::flip_buffer(buffer, buffer_size);
                }
                val = *reinterpret_cast<T*>(buffer);
                delete[] buffer;
            }
        };

        endistringstream::endistringstream() = default;
        endistringstream::~endistringstream() = default;

        endistringstream::endistringstream(std::istringstream&& is, endianness ness) : 
            super(std::move(is)), pImpl(std::make_unique<impl>(ness)) {
        }

        void endistringstream::swap(endistringstream& rhs) noexcept {
            using std::swap;
            super::swap(rhs);
            swap(this->pImpl, rhs.pImpl);
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

        endistringstream& endistringstream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        endistringstream& endistringstream::read(int16_t& val) {
            pImpl->parse<int16_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::read(int32_t& val) {
            pImpl->parse<int32_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::read(int64_t& val) {
            pImpl->parse<int64_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        endistringstream& endistringstream::read(uint16_t& val) {
            pImpl->parse<uint16_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::read(uint32_t& val) {
            pImpl->parse<uint32_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::read(uint64_t& val) {
            pImpl->parse<uint64_t>(this, val);
            return *this;
        }

        endistringstream& endistringstream::operator>>(int8_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(int16_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(int32_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(int64_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(uint8_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(uint16_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(uint32_t& val) {
            return read(val);
        }

        endistringstream& endistringstream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}

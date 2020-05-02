#include "endstream/buffer_util.h"
#include "endstream/endifstream.h"
#include "endstream/system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::ifstream super;

        struct endifstream::impl {
            endianness ness;

            impl(endianness ness) {
                this->ness = ness;
            }

            template<typename T>
            void parse(endifstream* parent, T& val) {
                size_t buffer_size = sizeof(T);
                char* buffer = new char[buffer_size];
                parent->read(buffer, buffer_size);
                if (!system_endianness::is_system_endianness(ness)) {
                    buffer_util::flip_buffer(buffer, buffer_size);
                }
                val = *reinterpret_cast<T*>(buffer);
                delete[] buffer;
            }
        };

        endifstream::endifstream() = default;
        endifstream::~endifstream() = default;

        endifstream::endifstream(std::ifstream&& is, endianness ness) :
            super(std::move(is)), pImpl(std::make_unique<impl>(ness)) {
        }

        void endifstream::swap(endifstream& rhs) noexcept {
            using std::swap;
            super::swap(rhs);
            swap(this->pImpl, rhs.pImpl);
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

        endianness endifstream::get_endianness() const {
            return pImpl->ness;
        }

        void endifstream::set_endianness(endianness ness) {
            pImpl->ness = ness;
        }

        void endifstream::flip_endianness() {
            pImpl->ness = (pImpl->ness == endianness::ES_BIG_ENDIAN) ?
                endianness::ES_LITTLE_ENDIAN :
                endianness::ES_BIG_ENDIAN;
        }

        endifstream& endifstream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        endifstream& endifstream::read(int16_t& val) {
            pImpl->parse<int16_t>(this, val);
            return *this;
        }

        endifstream& endifstream::read(int32_t& val) {
            pImpl->parse<int32_t>(this, val);
            return *this;
        }

        endifstream& endifstream::read(int64_t& val) {
            pImpl->parse<int64_t>(this, val);
            return *this;
        }

        endifstream& endifstream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        endifstream& endifstream::read(uint16_t& val) {
            pImpl->parse<uint16_t>(this, val);
            return *this;
        }

        endifstream& endifstream::read(uint32_t& val) {
            pImpl->parse<uint32_t>(this, val);
            return *this;
        }

        endifstream& endifstream::read(uint64_t& val) {
            pImpl->parse<uint64_t>(this, val);
            return *this;
        }

        endifstream& endifstream::operator>>(int8_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(int16_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(int32_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(int64_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(uint8_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(uint16_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(uint32_t& val) {
            return read(val);
        }

        endifstream& endifstream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}

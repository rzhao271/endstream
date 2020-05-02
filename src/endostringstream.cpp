#include "endstream/buffer_util.h"
#include "endstream/endostringstream.h"
#include "endstream/system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::ostringstream super;

        struct endostringstream::impl {
            endianness ness;

            impl(endianness ness) {
                this->ness = ness;
            }

            template<typename T>
            void write_as_char_array(endostringstream* parent, const T& val) {
                size_t buffer_size = sizeof(T);
                T dup = val;
                char *buffer = reinterpret_cast<char*>(&dup);
                if (!system_endianness::is_system_endianness(ness)) {
                    buffer_util::flip_buffer(buffer, buffer_size);
                }
                parent->write(buffer, buffer_size);
            }
        };

        endostringstream::endostringstream() = default;
        endostringstream::~endostringstream() = default;

        endostringstream::endostringstream(std::ostringstream&& os, endianness ness) :
            super(std::move(os)), pImpl(std::make_unique<impl>(ness)) {
        }

        void endostringstream::swap(endostringstream& rhs) noexcept {
            using std::swap;
            super::swap(rhs);
            swap(this->pImpl, rhs.pImpl);
        }

        void swap(endostringstream& first, endostringstream& second) noexcept {
            using std::swap;
            swap((std::ostringstream&)first, (std::ostringstream&)second);
            swap(first.pImpl, second.pImpl);
        }

        endostringstream::endostringstream(endostringstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
        }

        endostringstream& endostringstream::operator=(endostringstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
            return *this;
        }

        endianness endostringstream::get_endianness() const {
            return pImpl->ness;
        }

        void endostringstream::set_endianness(endianness ness) {
            pImpl->ness = ness;
        }

        void endostringstream::flip_endianness() {
            pImpl->ness = (pImpl->ness == endianness::ES_BIG_ENDIAN) ?
                endianness::ES_LITTLE_ENDIAN :
                endianness::ES_BIG_ENDIAN;
        }

        endostringstream& endostringstream::write(int8_t val) {
            const char* c = reinterpret_cast<char*>(&val);
            super::write(c, 1);
            return *this;
        }

        endostringstream& endostringstream::write(int16_t val) {
            pImpl->write_as_char_array<int16_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::write(int32_t val) {
            pImpl->write_as_char_array<int32_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::write(int64_t val) {
            pImpl->write_as_char_array<int64_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::write(uint8_t val) {
            const char* c = reinterpret_cast<char*>(&val);
            super::write(c, 1);
            return *this;
        }

        endostringstream& endostringstream::write(uint16_t val) {
            pImpl->write_as_char_array<uint16_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::write(uint32_t val) {
            pImpl->write_as_char_array<uint32_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::write(uint64_t val) {
            pImpl->write_as_char_array<uint64_t>(this, val);
            return *this;
        }

        endostringstream& endostringstream::operator<<(int8_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(int16_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(int32_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(int64_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(uint8_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(uint16_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(uint32_t val) {
            return write(val);
        }

        endostringstream& endostringstream::operator<<(uint64_t val) {
            return write(val);
        }
    }
}

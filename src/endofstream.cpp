#include "buffer_util.h"
#include "endofstream.h"
#include "system_endianness.h"

namespace rayzz {
    namespace endstream {
        typedef std::ofstream super;

        struct endofstream::impl {
            endianness ness;
            std::ofstream* parent;

            template<typename T>
            void write_as_char_array(const T& val) {
                size_t buffer_size = sizeof(T);
                T dup = val;
                char* buffer = reinterpret_cast<char*>(&dup);
                if (!system_endianness::is_system_endianness(ness)) {
                    buffer_util::flip_buffer(buffer, buffer_size);
                }
                parent->write(buffer, buffer_size);
            }
        };

        endofstream::endofstream() = default;
        endofstream::~endofstream() = default;

        endofstream::endofstream(
            std::ofstream&& os, 
            endianness ness) : super(std::move(os)) {
            pImpl = std::make_unique<impl>();
            pImpl->ness = ness;
            pImpl->parent = this;
        }

        void swap(endofstream& first, endofstream& second) noexcept {
            using std::swap;
            swap((std::ofstream&)first, (std::ofstream&)second);
            swap(first.pImpl, second.pImpl);
        }

        endofstream::endofstream(endofstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
        }

        endofstream& endofstream::operator=(endofstream&& other) noexcept {
            rayzz::endstream::swap(*this, other);
            return *this;
        }

        endianness endofstream::get_endianness() const {
            return pImpl->ness;
        }

        void endofstream::set_endianness(endianness ness) {
            pImpl->ness = ness;
        }

        void endofstream::flip_endianness() {
            pImpl->ness = (pImpl->ness == endianness::ES_BIG_ENDIAN) ?
                endianness::ES_LITTLE_ENDIAN :
                endianness::ES_BIG_ENDIAN;
        }

        std::ostream& endofstream::write(int8_t val) {
            const char* c = reinterpret_cast<char*>(val);
            super::write(c, 1);
            return *this;
        }

        std::ostream& endofstream::write(int16_t val) {
            pImpl->write_as_char_array<int16_t>(val);
            return *this;
        }

        std::ostream& endofstream::write(int32_t val) {
            pImpl->write_as_char_array<int32_t>(val);
            return *this;    
        }

        std::ostream& endofstream::write(int64_t val) {
            pImpl->write_as_char_array<int64_t>(val);
            return *this;    
        }

        std::ostream& endofstream::write(uint8_t val) {
            pImpl->write_as_char_array<uint8_t>(val);
            return *this;    
        }

        std::ostream& endofstream::write(uint16_t val) {
            pImpl->write_as_char_array<uint16_t>(val);
            return *this;    
        }

        std::ostream& endofstream::write(uint32_t val) {
            pImpl->write_as_char_array<uint32_t>(val);
            return *this;
        }

        std::ostream& endofstream::write(uint64_t val) {
            pImpl->write_as_char_array<uint64_t>(val);
            return *this;
        }

        std::ostream& endofstream::operator<<(int8_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(int16_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(int32_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(int64_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(uint8_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(uint16_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(uint32_t val) {
            return write(val);
        }

        std::ostream& endofstream::operator<<(uint64_t val) {
            return write(val);
        }
    }
}
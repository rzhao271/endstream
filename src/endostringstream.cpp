#include "endostringstream.h"
#include "endianness_helper.h"

namespace rayzz {
    namespace endstream {
        typedef std::ostringstream super;

        struct EndOutputStringStream::EndOutputStringStreamImpl {
            Endianness endianness;

            template<typename T>
            void write_as_char_array(const T& val) {
                size_t buffer_size = sizeof(T);
                char buffer[buffer_size];
                buffer = reinterpret_cast<char*>(&val);
                if (!EndiannessHelper::is_system_endianness(endianness)) {
                    EndiannessHelper::flip_buffer(buffer, num_bytes);
                }
                super::write(buffer, buffer_size);
            }
        };

        EndOutputStringStream::EndOutputStringStream(
            std::ostringstream& os, 
            Endianness endianness) : super(std::move(os)) {
            pImpl = std::make_unique<EndOutputStringStreamImpl>();
            pImpl->endianness = endianness;
        }

        EndOutputStringStream& EndOutputStringStream::write(int8_t val) {
            const char* c = reinterpret_cast<char*>(val);
            super::write(c, 1);
            return *this;
        }

        EndOutputStringStream& EndOutputStringStream::write(int16_t val) {
            pImpl->write_as_char_array<int16_t>(val);
            return *this;
        }

        EndOutputStringStream& EndOutputStringStream::write(int32_t val) {
            pImpl->write_as_char_array<int32_t>(val);
            return *this;    
        }

        EndOutputStringStream& EndOutputStringStream::write(int64_t val) {
            pImpl->write_as_char_array<int64_t>(val);
            return *this;    
        }

        EndOutputStringStream& EndOutputStringStream::write(uint8_t val) {
            pImpl->write_as_char_array<uint8_t>(val);
            return *this;    
        }

        EndOutputStringStream& EndOutputStringStream::write(uint16_t val) {
            pImpl->write_as_char_array<uint16_t>(val);
            return *this;    
        }

        EndOutputStringStream& EndOutputStringStream::write(uint32_t val) {
            pImpl->write_as_char_array<uint32_t>(val);
            return *this;
        }

        EndOutputStringStream& EndOutputStringStream::write(uint64_t val) {
            pImpl->write_as_char_array<uint64_t>(val);
            return *this;
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(int8_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(int16_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(int32_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(int64_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(uint8_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(uint16_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(uint32_t val) {
            return write(val);
        }

        EndOutputStringStream& EndOutputStringStream::operator<<(uint64_t val) {
            return write(val);
        }
    }
}
#include "endofstream.h"
#include "endianness_helper.h"

namespace rayzz {
    namespace endstream {
        typedef std::ofstream super;

        struct EndOutputFileStream::EndOutputFileStreamImpl {
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

        EndOutputFileStream::EndOutputFileStream(
            std::ofstream& os, 
            Endianness endianness) : super(std::move(os)) {
            pImpl = std::make_unique<EndOutputFileStreamImpl>();
            pImpl->endianness = endianness;
        }

        EndOutputFileStream& EndOutputFileStream::write(int8_t val) {
            const char* c = reinterpret_cast<char*>(val);
            super::write(c, 1);
            return *this;
        }

        EndOutputFileStream& EndOutputFileStream::write(int16_t val) {
            pImpl->write_as_char_array<int16_t>(val);
            return *this;
        }

        EndOutputFileStream& EndOutputFileStream::write(int32_t val) {
            pImpl->write_as_char_array<int32_t>(val);
            return *this;    
        }

        EndOutputFileStream& EndOutputFileStream::write(int64_t val) {
            pImpl->write_as_char_array<int64_t>(val);
            return *this;    
        }

        EndOutputFileStream& EndOutputFileStream::write(uint8_t val) {
            pImpl->write_as_char_array<uint8_t>(val);
            return *this;    
        }

        EndOutputFileStream& EndOutputFileStream::write(uint16_t val) {
            pImpl->write_as_char_array<uint16_t>(val);
            return *this;    
        }

        EndOutputFileStream& EndOutputFileStream::write(uint32_t val) {
            pImpl->write_as_char_array<uint32_t>(val);
            return *this;
        }

        EndOutputFileStream& EndOutputFileStream::write(uint64_t val) {
            pImpl->write_as_char_array<uint64_t>(val);
            return *this;
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(int8_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(int16_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(int32_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(int64_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(uint8_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(uint16_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(uint32_t val) {
            return write(val);
        }

        EndOutputFileStream& EndOutputFileStream::operator<<(uint64_t val) {
            return write(val);
        }
    }
}
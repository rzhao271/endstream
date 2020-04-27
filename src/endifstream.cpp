#include "endifstream.h"
#include "endianness_helper.h"

namespace rayzz {
    namespace endstream {
        typedef std::ifstream super;

        struct EndInputFileStream::EndInputFileStreamImpl {
            Endianness endianness;

            template<typename T>
            T parse() {
                size_t buffer_size = sizeof(T);
                char buffer[buffer_size];
                super::read(buffer, buffer_size);
                if (!EndiannessHelper::is_system_endianness(endianness)) {
                    EndiannessHelper::flip_buffer(buffer, num_bytes);
                }
                return *reinterpret_cast<T*>(buffer);
            }
        };

        EndInputFileStream::EndInputFileStream(std::ifstream& is, Endianness endianness) :
            super(std::move(is)) {
            pImpl = std::make_unique<EndInputFileStreamImpl>();
            pImpl->endianness = endianness;
        }

        EndInputFileStream& EndInputFileStream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(int16_t& val) {
            val = pImpl->parse<int16_t>();
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(int32_t& val) {
            val = pImpl->parse<int32_t>();
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(int64_t& val) {
            val = pImpl->parse<int64_t>();
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(uint16_t& val) {
            val = pImpl->parse<uint16_t>();
            return *this;
        }

        EndInputFileStream& EndInputFileStream::read(uint32_t& val) {
            val = pImpl->parse<uint32_t>();
            return *this;
        }
        
        EndInputFileStream& EndInputFileStream::read(uint64_t& val) {
            val = pImpl->parse<uint64_t>();
            return *this;
        }

        EndInputFileStream& EndInputFileStream::operator>>(int8_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(int16_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(int32_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(int64_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(uint8_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(uint16_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(uint32_t& val) {
            return read(val);
        }

        EndInputFileStream& EndInputFileStream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}
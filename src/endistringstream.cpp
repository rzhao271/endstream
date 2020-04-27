#include "endistringstream.h"
#include "endianness_helper.h"

namespace rayzz {
    namespace endstream {
        typedef std::istringstream super;

        struct EndInputStringStream::EndInputStringStreamImpl {
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

        EndInputStringStream::EndInputStringStream(
            std::istringstream& is, 
            Endianness endianness) : super(std::move(is)) {
            pImpl = std::make_unique<EndInputStringStreamImpl>();
            pImpl->endianness = endianness;
        }

        EndInputStringStream& EndInputStringStream::read(int8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<int8_t*>(buffer);
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(int16_t& val) {
            val = pImpl->parse<int16_t>();
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(int32_t& val) {
            val = pImpl->parse<int32_t>();
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(int64_t& val) {
            val = pImpl->parse<int64_t>();
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(uint8_t& val) {
            char buffer[1];
            super::read(buffer, 1);
            val = *reinterpret_cast<uint8_t*>(buffer);
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(uint16_t& val) {
            val = pImpl->parse<uint16_t>();
            return *this;
        }

        EndInputStringStream& EndInputStringStream::read(uint32_t& val) {
            val = pImpl->parse<uint32_t>();
            return *this;
        }
        
        EndInputStringStream& EndInputStringStream::read(uint64_t& val) {
            val = pImpl->parse<uint64_t>();
            return *this;
        }

        EndInputStringStream& EndInputStringStream::operator>>(int8_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(int16_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(int32_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(int64_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(uint8_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(uint16_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(uint32_t& val) {
            return read(val);
        }

        EndInputStringStream& EndInputStringStream::operator>>(uint64_t& val) {
            return read(val);
        }
    }
}
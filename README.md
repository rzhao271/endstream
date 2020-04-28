# EndStream

## About

EndStream is a C++ library that provides some classes that extend the following stream classes:

- `std::ifstream` becomes `rayzz::endstream::endifstream`
- `std::ofstream` becomes `rayzz::endstream::endofstream`
- `std::istringstream` becomes `rayzz::endstream::endistringstream`
- `std::ostringstream` becomes `rayzz::endstream::endostringstream`

The user can specify which endianness to use while defining the helper class, 
and change the endianness midway through, too.

## Full Example

The following program writes an unsigned 16-bit integer with a value of 2,
and a signed 32-bit integer with a value of 3,
to a binary file `foo.out`. It writes the values in little-endian.
The file is overwritten if it already exists.

```cpp
#include <fstream>
#include "rayzz/endstream"

int main() {
    using namespace rayzz::endstream;
    endofstream fout(
        std::ofstream("foo.out", std::ios::binary | std::ios::trunc),
        endianness::ES_LITTLE_ENDIAN);
    uint16_t foo = 2;
    int32_t bar = 3;
    fout << foo << bar;
    return 0;
}
```

## Requirements

- A compiler that can compile C++14.
- g++ with version >= 5, since there is a bug with the move constructor in the stream objects for older g++ compilers.
- CMake version >= 3.17.1

## Restrictions

As soon as the stream is passed in to a wrapper class, the wrapper class will own the stream.
Therefore, the stream is inaccessible outside of the wrapper class, and the lifetime of the stream ends when the lifetime of the wrapper class ends.
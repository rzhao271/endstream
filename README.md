# EndStream

![Travis (.com) branch](https://img.shields.io/travis/com/rzhao271/endstream/master) ![Coverity Scan](https://img.shields.io/coverity/scan/20997)

## About

EndStream is a C++ library with classes that extend the following streams:

- `rayzz::endstream::endifstream` extends `std::ifstream`
- `rayzz::endstream::endofstream` extends `std::ofstream`
- `rayzz::endstream::endistringstream` extends `std::istringstream`
- `rayzz::endstream::endostringstream` extends `std::ostringstream`

The user can specify which endianness to use while defining the helper class, 
and change the endianness midway through, too.

## Sample

Check out [this C++ program](sample/src/main.cpp).

## Requirements

- A C++ compiler that can compile C++14.
- CMake version >= 3.1
- If you're using g++, it must be at least version 5 (see https://stackoverflow.com/q/28775673 for details)

## Limitations

As soon as the stream is passed in to a wrapper class, the wrapper class will own the stream.
Therefore, the stream is inaccessible outside of the wrapper class, and the lifetime of the stream ends when the lifetime of the wrapper class ends.

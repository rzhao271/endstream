cmake_minimum_required(VERSION 2.8.8)
cmake_policy(SET CMP0048 NEW)

set(this endstream)

project(${this} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest-release-1.10.0)

include_directories(include)

file(GLOB src src/*.cpp)

add_library(${this} STATIC ${src})

add_subdirectory(test)

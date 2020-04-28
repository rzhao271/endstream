cmake_minimum_required(VERSION 3.17.1)

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
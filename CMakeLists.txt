cmake_minimum_required(VERSION 2.8.8)
cmake_policy(SET CMP0048 NEW)

set(this endstream)
project(${this} VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)
file(GLOB src src/*.cpp)

enable_testing()
add_subdirectory(googletest-release-1.10.0)
add_subdirectory(test)

add_library(${this} STATIC ${src})

add_subdirectory(sample)

cmake_minimum_required(VERSION 2.8.8)
cmake_policy(SET CMP0048 NEW)

set(GCC_WARN_FLAGS "-Wall -Wpedantic -Werror")

set(this endstreamsample)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS}")
file(GLOB src src/*.cpp)
add_executable(${this} ${src})

target_link_libraries(${this} PUBLIC endstream)

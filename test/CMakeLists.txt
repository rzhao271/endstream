cmake_minimum_required(VERSION 3.17.1)

set(GCC_WARN_FLAGS "-Wall -Wpedantic -Werror")

set(this endstreamtests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS}")
file(GLOB src src/*.cpp)
add_executable(${this} ${src})

target_link_libraries(${this} PUBLIC gtest_main endstream)
add_test(NAME ${this} COMMAND ${this})

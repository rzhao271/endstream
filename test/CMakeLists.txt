cmake_minimum_required(VERSION 3.17.1)

set(this endstreamtests)
file(GLOB src *.cpp)
add_executable(${this} ${src})

target_link_libraries(${this} PUBLIC gtest_main endstream)
add_test(NAME ${this} COMMAND ${this})

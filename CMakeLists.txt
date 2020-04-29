cmake_minimum_required(VERSION 3.1)
if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

set(this endstream)
set(main_project_name ${this}) # for child files
project(${this} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CYGWIN)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(GCC_WARN_FLAGS "-Wall -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS}")

file(GLOB headers "${CMAKE_SOURCE_DIR}/include/${this}/*.h")
file(GLOB src "${CMAKE_SOURCE_DIR}/src/*.cpp")

enable_testing()
add_subdirectory(googletest-release-1.10.0)
add_subdirectory(test)

add_library(${this} STATIC ${headers} ${src})
target_include_directories(${this} PUBLIC "${CMAKE_SOURCE_DIR}/include")


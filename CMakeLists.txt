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
set(GCC_COVERAGE_FLAGS "-O0 -g -fprofile-arcs -ftest-coverage --coverage")
set(GCC_COVERAGE_LINK_FLAGS "-lgcov --coverage")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS}")

file(GLOB headers "${CMAKE_SOURCE_DIR}/include/${this}/*.h")
file(GLOB src "${CMAKE_SOURCE_DIR}/src/*.cpp")

# from https://github.com/codecov/example-cpp11-cmake/blob/master/CMakeLists.txt
option(CODE_COVERAGE "Enable coverage reporting." OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  # Add required flags (GCC & LLVM/Clang)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
endif()

option(BUILD_TESTS "Build the tests." ON)
if (BUILD_TESTS AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
  enable_testing()
  add_subdirectory("lib/googletest-release-1.10.0")
  add_subdirectory(tests)
endif()

add_library(${this} STATIC ${headers} ${src})
target_include_directories(${this} PUBLIC "${CMAKE_SOURCE_DIR}/include")

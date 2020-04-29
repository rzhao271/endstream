set(this endstream_tests)

set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS} ${GCOV_FLAGS}")

file(GLOB headers "${CMAKE_SOURCE_DIR}/include/${main_project_name}/*.h")
file(GLOB src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${this} ${headers} ${src})
target_link_libraries(${this} PUBLIC gtest_main endstream)
add_test(NAME ${this} COMMAND ${this})

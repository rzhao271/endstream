set(this "${main_project_name}_tests")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARN_FLAGS}")

file(GLOB headers "${CMAKE_SOURCE_DIR}/include/${main_project_name}/*.h")
file(GLOB src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${this} ${headers} ${src})
target_link_libraries(${this} PUBLIC gtest_main ${main_project_name})
add_test(NAME ${this} COMMAND ${this})

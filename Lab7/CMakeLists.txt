cmake_minimum_required(VERSION 3.17)
project(lab7)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(lab7 header.h student.cpp TESTS.cpp)
target_link_libraries(lab7 gtest gtest_main)
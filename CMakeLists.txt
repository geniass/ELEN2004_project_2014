cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-std=c++11")
project(elen2004)
enable_testing()

add_subdirectory(gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include)
add_subdirectory(src)
include_directories(src)

add_executable(runUnitTests
    DataPoint_test.cpp
)

target_link_libraries(runUnitTests src gtest gtest_main)

add_test(
    NAME runUnitTests
    COMMAND runUnitTests
)

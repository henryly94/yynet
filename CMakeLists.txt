cmake_minimum_required(VERSION 3.12)

project(yynet VERSION 1.0)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
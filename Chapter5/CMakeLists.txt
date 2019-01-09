cmake_minimum_required(VERSION 3.0.0)

project(chapter5)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
add_executable(kmp kmp.cpp)
cmake_minimum_required(VERSION 3.22)
project(laba5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(laba5
        laba5.cpp
        MySet.h
        MyVector.h)

cmake_minimum_required(VERSION 3.21)
project(proj5_provided)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj5_provided
        hashtable.h
        hashtable.hpp
        myspell.cpp)

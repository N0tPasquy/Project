cmake_minimum_required(VERSION 3.27)
project(blockchain)

set(CMAKE_CXX_STANDARD 11)

add_executable(blockchain main.cpp
        header.hpp)

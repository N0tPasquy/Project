cmake_minimum_required(VERSION 3.29)
project(gioco_del_15)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)

add_executable(gioco_del_15
        main.cpp)
target_link_libraries(gioco_del_15 PRIVATE ${CMAKE_THREAD_LIBS_INIT})

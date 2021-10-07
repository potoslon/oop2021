cmake_minimum_required(VERSION 3.16)
project(lab3_main)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3_main main.cpp dop_funcs.cpp dop_funcs.h)

include_directories(../class_kardioida/)

target_link_libraries(lab3_main lab3_lib)
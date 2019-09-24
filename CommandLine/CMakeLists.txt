cmake_minimum_required(VERSION 3.14)
project(CommandLine)

set(CMAKE_CXX_STANDARD 17)

add_executable(CommandLine main.cpp CommandLine.cpp CommandLine.h Utils.h)
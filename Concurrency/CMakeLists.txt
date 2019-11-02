cmake_minimum_required(VERSION 3.14)
project(testing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -DNDEBUG -pthread ")

add_executable(testing main.cpp SaveQueue.h ThreadPool.cpp ThreadPool.h SaveQueue2.h SaveList.h)

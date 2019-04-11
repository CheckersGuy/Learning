cmake_minimum_required(VERSION 3.10)
project(testing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -ffast-math -pthread -DNDEBUG -march=native   -flto -ffat-lto-objects -fuse-linker-plugin ")
add_executable(testing main.cpp)
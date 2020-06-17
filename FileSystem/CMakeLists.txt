cmake_minimum_required(VERSION 3.16)
project(FileSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Ofast -pthread -DNDEBUG -march=native -flto -ffat-lto-objects -fuse-linker-plugin ")


add_executable(FileSystem main.cpp)
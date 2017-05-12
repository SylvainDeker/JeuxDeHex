cmake_minimum_required(VERSION 3.6)
project(DmAlgo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES dmalgo.c dmalgo.h dmAlgomain.c)
add_executable(DmAlgo ${SOURCE_FILES} dmalgo.c dmalgo.h dmAlgomain.c)
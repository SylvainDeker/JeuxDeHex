cmake_minimum_required(VERSION 3.6)
project(SystemeTP3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES TP3/manipulation.c TP3/manipulation.h TP3/manipulationMain.c)
add_executable(SystemeTP3 ${SOURCE_FILES})
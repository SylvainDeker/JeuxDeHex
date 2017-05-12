cmake_minimum_required(VERSION 3.6)
project(ProjetAlgo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sudoku.c sudoku.h sudokumain.c)
add_executable(ProjetAlgo ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.15)
project(OpenMP_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(OpenMP_1 main.c matrix/scaning.c matrix/scaning.h matrix/matrix.c matrix/matrix.h matrix/column.c matrix/column.h sole.c sole.h)
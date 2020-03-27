cmake_minimum_required(VERSION 3.15)
project(OpenMP_2 C)

set(CMAKE_C_COMPILER /usr/local/bin/g++-9)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

include_directories(/usr/local/opt/libomp/include)
link_directories(/usr/local/opt/libomp/lib)

add_executable(OpenMP_3 main.c matrix/scaning.c matrix/scaning.h matrix/matrix.c matrix/matrix.h matrix/column.c matrix/column.h sole.c sole.h)

target_link_libraries(OpenMP_3 omp)
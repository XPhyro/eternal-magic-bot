cmake_minimum_required(VERSION 3.17)
project(em_red_to_blue C)

set(CMAKE_C_STANDARD 11)
# set(GCC_COVERAGE_COMPILE_FLAGS "-O3")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(em_red_to_blue main.c input.h input.c soln.h soln.c)
cmake_minimum_required(VERSION 3.17)
project(em_red_to_blue C)

set(CMAKE_C_STANDARD 11)

add_executable(em_red_to_blue main.c input.h input.c soln.h soln.c)
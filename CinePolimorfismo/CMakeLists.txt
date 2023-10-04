cmake_minimum_required(VERSION 3.19)
project(em)

set(CMAKE_CXX_STANDARD 14)

add_executable(em main.cpp Pelicula.h Serie.h Video.h)
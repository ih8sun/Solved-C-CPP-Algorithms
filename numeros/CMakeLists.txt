cmake_minimum_required(VERSION 3.19)
project(numeros)

set(CMAKE_CXX_STANDARD 14)

add_executable(numeros main.cpp Numero.h Binario.h Decimal.h)
cmake_minimum_required(VERSION 3.25)
project(prueba)

set(CMAKE_CXX_STANDARD 14)

add_executable(prueba src/main.cpp src/Language.cpp src/BigramFreq.cpp src/Bigram.cpp include/Language.h)

cmake_minimum_required(VERSION 3.25)
project(Language2_Florin)

set(CMAKE_CXX_STANDARD 11)

add_executable(Language2_Florin src/main.cpp src/Bigram.cpp src/BigramFreq.cpp src/Language.cpp include/Language.h)

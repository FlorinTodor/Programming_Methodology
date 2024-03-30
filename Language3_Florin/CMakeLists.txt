cmake_minimum_required(VERSION 3.25)
project(Language3_Florin)

set(CMAKE_CXX_STANDARD 14)

add_executable(Language3_Florin src/main.cpp src/Language.cpp src/BigramFreq.cpp src/Bigram.cpp include/Language.h)

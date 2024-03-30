cmake_minimum_required(VERSION 3.25)
project(Language5_Florin)

set(CMAKE_CXX_STANDARD 14)
add_executable(Language5_Florin src/BigramCounter.cpp src/classify.cpp src/joinLanguages.cpp src/Language.cpp src/learn.cpp src/metamain.cpp src/Bigram.cpp src/BigramFreq.cpp src/main_prueba.cpp)

cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__ main.cpp Digit.h Matrix.h MlpNetwork.h Activation.h Matrix.cpp Digit.cpp MlpNetwork.cpp Activation.cpp Dense.cpp Dense.h)
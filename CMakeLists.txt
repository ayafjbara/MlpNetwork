cmake_minimum_required(VERSION 3.14.5)
project(MlpNetwork)

set(CMAKE_CXX_STANDARD 17)
set(CXXFLAGS "${CMAKE_CXX_FLAGS} -Wall -Wvla -Wextra -Werror -g -std=c++17")

add_executable(MlpNetwork main.cpp Digit.h Matrix.h MlpNetwork.h Activation.h Matrix.cpp Digit.cpp MlpNetwork.cpp Activation.cpp Dense.cpp Dense.h)
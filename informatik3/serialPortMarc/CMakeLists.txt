cmake_minimum_required(VERSION 3.15)
project(serialPortMarc)

set(CMAKE_CXX_STANDARD 14)

add_executable(serialPortMarc main.cpp SerialPort.cpp SerialPort.hpp)
cmake_minimum_required(VERSION 3.15)
project(TOF_driver)

set(CMAKE_CXX_STANDARD 17)

add_executable(TOF_driver main.cpp serial.cpp serial.h sensor_constants.cpp sensor_constants.h crc16.cpp crc16.h packet.cpp packet.h)
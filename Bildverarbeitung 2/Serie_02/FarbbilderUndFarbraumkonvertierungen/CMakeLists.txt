find_package(OpenCV REQUIRED)

cmake_minimum_required(VERSION 3.17)
project(FarbbilderUndFarbraumkonvertierungen)

set(CMAKE_CXX_STANDARD 20)

add_executable(FarbbilderUndFarbraumkonvertierungen main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(FarbbilderUndFarbraumkonvertierungen ${OpenCV_LIBS})
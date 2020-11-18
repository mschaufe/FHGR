find_package(OpenCV REQUIRED) # after project()

cmake_minimum_required(VERSION 3.17)
project(Morphologische_Operationen)

set(CMAKE_CXX_STANDARD 17)

add_executable(Morphologische_Operationen main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Morphologische_Operationen ${OpenCV_LIBS})
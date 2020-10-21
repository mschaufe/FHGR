find_package(OpenCV REQUIRED) # after project()

cmake_minimum_required(VERSION 3.17)
project(GeometrischeTransformationen)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeometrischeTransformationen main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(GeometrischeTransformationen ${OpenCV_LIBS})
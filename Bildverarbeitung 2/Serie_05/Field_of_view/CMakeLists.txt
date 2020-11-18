find_package(OpenCV REQUIRED) # after project()

cmake_minimum_required(VERSION 3.17)
project(Field_of_view)

set(CMAKE_CXX_STANDARD 17)

add_executable(Field_of_view main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Field_of_view ${OpenCV_LIBS})
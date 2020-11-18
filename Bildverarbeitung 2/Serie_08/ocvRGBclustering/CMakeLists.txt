find_package(OpenCV REQUIRED) # after project()

cmake_minimum_required(VERSION 3.17)
project(ocvRGBclustering)

set(CMAKE_CXX_STANDARD 17)

add_executable(ocvRGBclustering main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ocvRGBclustering ${OpenCV_LIBS})
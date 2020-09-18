find_package(OpenCV REQUIRED)

cmake_minimum_required(VERSION 3.15)
project(LaplaceFilter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Principal_Component_Analysis main.cpp)

#At the end
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Principal_Component_Analysis ${OpenCV_LIBS})
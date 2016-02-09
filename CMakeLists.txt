cmake_minimum_required(VERSION 3.3)
project(AsciiArtStudioCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp)
add_executable(AsciiArtStudioCPP ${SOURCE_FILES})
target_link_libraries(AsciiArtStudioCPP ${OpenCV_LIBS})
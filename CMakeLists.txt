cmake_minimum_required(VERSION 3.29)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "main.cpp")

add_executable(code ${SOURCES})

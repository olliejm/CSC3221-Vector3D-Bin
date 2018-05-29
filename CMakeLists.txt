cmake_minimum_required(VERSION 3.8)
project(CSC3221_Project_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Vector3D.cpp Vector3D.h Test.cpp Bin.cpp Bin.h)
add_executable(CSC3221_Project_1 ${SOURCE_FILES})
cmake_minimum_required(VERSION 2.6)
# =========================================================
# RayTrace - A simple raytrace framework for C++.
# =========================================================

project(RayTrace)

set(CMAKE_CXX_COMPILER_VERSION c++11)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")

# Define interfaces in the include directory.
include_directories(include)

# Implement some defined interfaces.
add_subdirectory(src bin)

# Lets run some tests.
include(CTest)
enable_testing()
add_subdirectory(test testbin)

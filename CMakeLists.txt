cmake_minimum_required(VERSION 3.27)
project(cpp20-examples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minimal-example minimalExample.cpp)

include(concepts/CMakeLists.txt)
include(lambda-expression/CMakeLists.txt)
include(ranges/CMakeLists.txt)
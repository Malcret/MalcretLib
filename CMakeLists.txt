cmake_minimum_required(VERSION 3.20)
project(MalcretLib LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(MLTLIB_BUILD_TESTS "Build test programs" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(mltlib)
add_subdirectory(test)

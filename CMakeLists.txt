cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("PhysicalEngine")
add_subdirectory ("PhysicalEngine")

project("PhysicalEngineUnitTest")
enable_testing()
add_subdirectory("test")

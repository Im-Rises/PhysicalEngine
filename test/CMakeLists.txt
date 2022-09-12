cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("NesEmuTests")

set(SRCS "mainTest.cpp" ../PhysicalEngine/main.cpp)
set(HEADERS)

enable_testing()

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

add_test(${PROJECT_NAME} ${PROJECT_NAME})

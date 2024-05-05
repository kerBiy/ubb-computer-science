cmake_minimum_required(VERSION 3.27)
project(RareMatrix)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES
        src/App.cpp
        src/Matrice.cpp
        tests/TestScurt.cpp
        tests/TestExtins.cpp
)

add_executable(RareMatrix ${SOURCES})

target_include_directories(RareMatrix
        PRIVATE include
        PRIVATE tests/headers
)
cmake_minimum_required(VERSION 3.27)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES
        src/App.cpp
        src/CP.cpp
        tests/TestScurt.cpp
        tests/TestExtins.cpp
)

add_executable(PriorityQueue ${SOURCES})

target_include_directories(PriorityQueue
        PRIVATE include
        PUBLIC tests/headers
)
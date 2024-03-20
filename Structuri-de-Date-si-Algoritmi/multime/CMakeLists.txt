cmake_minimum_required(VERSION 3.27)
project(multime)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES
        src/App.cpp
        src/Multime.cpp
        src/IteratorMultime.cpp
        tests/TestExtins.cpp
        tests/TestScurt.cpp
)

add_executable(multime ${SOURCES})

target_include_directories(multime
        PUBLIC include
        PUBLIC tests
)
cmake_minimum_required(VERSION 3.28)
project(MultimeABC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


set(SOURCES
        src/App.cpp
        src/Multime.cpp
        src/IteratorMultime.cpp
        tests/TestExtins.cpp
        tests/TestScurt.cpp
)

add_executable(MultimeABC ${SOURCES})

target_include_directories(MultimeABC
        PUBLIC include
        PUBLIC tests/headers
)
cmake_minimum_required(VERSION 3.27)
project(MDO)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES
        src/App.cpp
        src/IteratorMDO.cpp
        src/MDO.cpp
        tests/TestScurt.cpp
        tests/TestExtins.cpp
)

add_executable(MDO ${SOURCES})

target_include_directories(MDO
        PRIVATE include
        PUBLIC tests/headers
)
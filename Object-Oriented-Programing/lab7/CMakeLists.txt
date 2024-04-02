cmake_minimum_required(VERSION 3.27)
project(lab7)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCES
        src/main.cpp
        src/Test.cpp
        src/Book.cpp
        src/Repository.cpp
        src/Service.cpp
        src/Console.cpp
        include/List.hpp
)

add_executable(lab7 ${SOURCES})

target_include_directories(lab7
        PUBLIC include
)

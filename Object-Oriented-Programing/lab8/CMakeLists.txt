cmake_minimum_required(VERSION 3.27)
project(lab8)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCES
        src/main.cpp
        src/Test.cpp
        src/Book.cpp
        src/Repository.cpp
        src/Service.cpp
        src/Console.cpp
        src/Validator.cpp
        include/Validator.hpp
)

add_executable(lab8 ${SOURCES})

target_include_directories(lab8
        PUBLIC include
)

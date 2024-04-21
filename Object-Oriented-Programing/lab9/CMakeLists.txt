cmake_minimum_required(VERSION 3.27)
project(lab9)

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
        src/Undo.cpp
        src/ConsoleSC.cpp
)

add_executable(lab9 ${SOURCES})

target_include_directories(lab9
        PUBLIC include
)

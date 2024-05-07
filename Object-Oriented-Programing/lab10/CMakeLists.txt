cmake_minimum_required(VERSION 3.27)
project(lab10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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
        src/GUI.cpp
)

add_executable(lab10 ${SOURCES})

target_include_directories(lab10
        PUBLIC include
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(lab10
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

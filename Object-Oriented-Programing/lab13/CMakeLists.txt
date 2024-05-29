cmake_minimum_required(VERSION 3.27)
project(lab13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
        src/main.cpp
        src/Test.cpp
        src/Book.cpp
        src/Repository.cpp
        src/Service.cpp
        src/Console.cpp
        src/Validator.cpp
        src/Undo.cpp
        src/TableModel.cpp
        src/GUI.cpp
        src/ShoppingCartWindow.cpp
        src/ListModel.cpp
        src/ShoppingCartDrawing.cpp
)

add_executable(lab13 ${SOURCES})

target_include_directories(lab13
        PUBLIC include
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

target_link_libraries(lab13
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

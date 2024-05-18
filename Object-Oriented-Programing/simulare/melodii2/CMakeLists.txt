cmake_minimum_required(VERSION 3.28)
project(melodii2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(melodii2 main.cpp
        Song.hpp
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        MainWindow.cpp
        MainWindow.hpp
        SongModel.cpp
        SongModel.hpp)

target_link_libraries(melodii2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


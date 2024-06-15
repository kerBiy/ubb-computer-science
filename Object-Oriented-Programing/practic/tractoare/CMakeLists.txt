cmake_minimum_required(VERSION 3.28)
project(tractoare)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(tractoare main.cpp
        Track.hpp
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Observer.hpp
        MainWindow.cpp
        MainWindow.hpp
        Model.cpp
        Model.hpp)
target_link_libraries(tractoare
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


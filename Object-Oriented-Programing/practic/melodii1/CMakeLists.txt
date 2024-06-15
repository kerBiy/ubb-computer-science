cmake_minimum_required(VERSION 3.28)
project(melodii1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(melodii1 main.cpp
        Entity.cpp
        Entity.hpp
        songs.txt
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Test.cpp
        Test.hpp
        MainWindow.cpp
        MainWindow.hpp
        Model.cpp
        Model.hpp
        Observer.hpp
)

target_link_libraries(melodii1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


cmake_minimum_required(VERSION 3.28)
project(produse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(produse main.cpp
        Product.hpp
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Model.cpp
        Model.hpp
        GUI.cpp
        GUI.hpp)
target_link_libraries(produse
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


cmake_minimum_required(VERSION 3.28)
project(tasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(tasks main.cpp
        Task.hpp
        Test.cpp
        Test.hpp
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Model.cpp
        Model.hpp
        GUI.cpp
        GUI.hpp
        StatusWindow.hpp
        StatusWindow.cpp)
target_link_libraries(tasks
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


cmake_minimum_required(VERSION 3.28)
project(task)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task main.cpp
        Task.hpp
        Repository.cpp
        Repository.hpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Model.cpp
        Model.hpp
        MainWindow.cpp
        MainWindow.hpp
        StatusWindow.cpp
        StatusWindow.hpp
        Observer.hpp
        Test.cpp
        Test.hpp)
target_link_libraries(task
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


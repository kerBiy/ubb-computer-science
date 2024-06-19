cmake_minimum_required(VERSION 3.28)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(test main.cpp
        Task.hpp
        Repository.cpp
        Repository.hpp
        Service.cpp
        Service.hpp
        Observer.hpp
        Model.cpp
        Model.hpp
        MainWindow.cpp
        MainWindow.hpp
        StatusWindow.cpp
        StatusWindow.hpp
        Test.cpp
        Test.hpp)
target_link_libraries(test
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


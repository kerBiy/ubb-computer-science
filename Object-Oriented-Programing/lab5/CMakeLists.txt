cmake_minimum_required(VERSION 3.27)
project(lab5 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(lab5 main.c
        Domain/medicament.c
        Domain/medicament.h
        Validator/validator.c
        Validator/validator.h
        Domain/lista.c
        Domain/lista.h
        Tests/tests.c
        Tests/tests.h
        Service/Service.c
        Service/Service.h
        Ui/Menu.c
        Ui/Menu.h
        Utility/Utility.c
        Utility/Utility.h)

cmake_minimum_required(VERSION 3.27)
project(lab4 C)

set(CMAKE_C_STANDARD 23)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
        src/entity.c
        src/repository.c
        src/validator.c
        src/service.c
        src/console.c
        src/tests.c
        src/main.c
)

# Add an executable with the above sources
add_executable(lab4 ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(lab4
        PRIVATE include
)
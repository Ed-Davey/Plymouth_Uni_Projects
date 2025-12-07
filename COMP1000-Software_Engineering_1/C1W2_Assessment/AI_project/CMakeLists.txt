cmake_minimum_required(VERSION 3.24)
project(MysteryMaze)

set(CMAKE_CXX_STANDARD 17)

# Include the header files directory
include_directories(include)

# Add all source files
file(GLOB SOURCES src/*.cpp)

# Create the executable
add_executable(MysteryMaze main.cpp ${SOURCES}
        include/MazeGeneration.h
        include/PlayerMovement.h
        include/Position.h)

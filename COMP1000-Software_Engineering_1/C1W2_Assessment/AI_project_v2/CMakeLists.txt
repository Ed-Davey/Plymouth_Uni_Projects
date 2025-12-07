cmake_minimum_required(VERSION 3.29)
project(AI_project_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(AI_project_v2 main.cpp
        Maze.cpp
        Player.cpp
        Enemy.cpp
        Puzzle.cpp
        Game.cpp
        Enemy.h
        Game.h
        Maze.h
        Player.h
        Puzzle.h)

#include "Maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Maze::Maze(int width, int height) : width(width), height(height) {
    maze.resize(height, std::vector<char>(width, '#')); // Initialize maze with walls
    generateMaze();
}

void Maze::generateMaze() {
    // Simple maze generation logic (placeholder)
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            maze[i][j] = (rand() % 2) ? ' ' : '#'; // Randomly place walls
        }
    }
    maze[1][1] = 'S'; // Start
    maze[height - 2][width - 2] = 'E'; // Exit
}

void Maze::displayMaze() {
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

char Maze::getCell(int x, int y) {
    return maze[y][x];
}

void Maze::setCell(int x, int y, char value) {
    maze[y][x] = value;
}
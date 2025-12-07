// MazeGeneration.cpp
#include "../include/MazeGeneration.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random> // For random number generation
#include <vector>

MazeGenerator::MazeGenerator(int width, int height)
    : width(width), height(height), maze(height, std::vector<char>(width, '#')) {}

void MazeGenerator::generate() {
    carvePath(1, 1); // Start carving from (1, 1)
}

void MazeGenerator::carvePath(int x, int y) {
    std::vector<std::pair<int, int>> directions = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    static std::random_device rd;
    static std::default_random_engine rng(rd());

    std::shuffle(directions.begin(), directions.end(), rng);

    for (const auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx > 0 && ny > 0 && nx < width - 1 && ny < height - 1 && maze[ny][nx] == '#') {
            maze[y + dir.second / 2][x + dir.first / 2] = ' ';
            maze[ny][nx] = ' ';
            carvePath(nx, ny);
        }
    }
}

void MazeGenerator::renderWithPlayer(const Position& playerPos, const std::vector<Enemy>& enemies) const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            bool isPlayer = (x == playerPos.x && y == playerPos.y);
            bool isEnemy = false;

            for (const auto& enemy : enemies) {
                if (x == enemy.getPosition().x && y == enemy.getPosition().y) {
                    isEnemy = true;
                    break;
                }
            }

            if (isPlayer) {
                std::cout << "😀"; // Player
            } else if (isEnemy) {
                std::cout << "👾"; // Enemy
            } else if (maze[y][x] == '#') {
                std::cout << "⬛"; // Wall
            } else {
                std::cout << "⬜"; // Path
            }
        }
        std::cout << '\n';
    }
}

const std::vector<std::vector<char>>& MazeGenerator::getMaze() const {
    return maze;
}

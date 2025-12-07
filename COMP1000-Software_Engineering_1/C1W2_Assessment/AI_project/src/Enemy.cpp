// Enemy.cpp
#include "../include/Enemy.h"
#include <cstdlib>
#include <vector>

Enemy::Enemy(int startX, int startY) : pos{startX, startY} {}

Position Enemy::getPosition() const {
    return pos;
}

void Enemy::move(const std::vector<std::vector<char>>& maze) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int randDir = std::rand() % 4;

    int newX = pos.x + directions[randDir][0];
    int newY = pos.y + directions[randDir][1];

    if (maze[newY][newX] == ' ') {
        pos.x = newX;
        pos.y = newY;
    }
}

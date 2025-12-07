#include "Enemy.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy(int startX, int startY) : x(startX), y(startY) {}

void Enemy::move() {
    // Simple random movement logic (placeholder)
    int direction = rand() % 4;
    switch (direction) {
        case 0: y--; break; // Up
        case 1: y++; break; // Down
        case 2: x--; break; // Left
        case 3: x++; break; // Right
    }
}

void Enemy::displayPosition() {
    std::cout << "Enemy Position: (" << x << ", " << y << ")" << std::endl;
}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}
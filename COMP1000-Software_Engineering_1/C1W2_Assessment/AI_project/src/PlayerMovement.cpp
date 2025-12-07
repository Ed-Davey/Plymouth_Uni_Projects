// PlayerMovement.cpp
#include "../include/PlayerMovement.h"
#include <vector>

Player::Player(int startX, int startY) : pos{startX, startY} {}

Position Player::getPosition() const {
    return pos;
}

bool Player::move(char direction, const std::vector<std::vector<char>>& maze) {
    int newX = pos.x;
    int newY = pos.y;

    switch (direction) {
        case 'W': newY -= 1; break; // Move up
        case 'S': newY += 1; break; // Move down
        case 'A': newX -= 1; break; // Move left
        case 'D': newX += 1; break; // Move right
    }

    if (maze[newY][newX] == ' ') {
        pos.x = newX;
        pos.y = newY;
        return true;
    }

    return false;
}

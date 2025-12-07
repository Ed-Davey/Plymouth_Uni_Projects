#include "Player.h"
#include <iostream>

Player::Player(int startX, int startY) : x(startX), y(startY) {}

void Player::move(char direction) {
    switch (direction) {
        case 'w': y--; break; // Up
        case 's': y++; break; // Down
        case 'a': x--; break; // Left
        case 'd': x++; break; // Right
    }
}

void Player::displayPosition() {
    std::cout << "Player Position: (" << x << ", " << y << ")" << std::endl;
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}
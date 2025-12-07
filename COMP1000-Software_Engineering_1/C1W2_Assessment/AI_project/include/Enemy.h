// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Position.h"  // Include Position.h
#include <vector>

class Enemy {
public:
    Enemy(int x, int y);
    Position getPosition() const;
    void move(const std::vector<std::vector<char>>& maze); // Define the move function
private:
    Position pos;
};

#endif // ENEMY_H

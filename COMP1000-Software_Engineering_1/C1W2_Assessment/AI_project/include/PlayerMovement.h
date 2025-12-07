// PlayerMovement.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"  // Include Position.h for Position type
#include <vector>

class Player {
public:
    Player(int startX, int startY);
    Position getPosition() const;
    bool move(char direction, const std::vector<std::vector<char>>& maze);

private:
    Position pos;
};

#endif // PLAYER_H

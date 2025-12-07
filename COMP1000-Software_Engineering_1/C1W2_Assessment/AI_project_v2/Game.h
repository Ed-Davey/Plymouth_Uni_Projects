#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include "Player.h"
#include "Enemy.h"
#include "Puzzle.h"

class Game {
public:
    Game();
    void start();
    void handlePlayerMove(char move);
    void checkGameState();

private:
    Maze maze;
    Player player;
    Enemy enemy;
    Puzzle puzzle;
};

#endif // GAME_H
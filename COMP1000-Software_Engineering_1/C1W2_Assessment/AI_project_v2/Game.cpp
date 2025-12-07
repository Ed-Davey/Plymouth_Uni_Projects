#include "Game.h"
#include <iostream>

Game::Game() : maze(10, 10), player(1, 1), enemy(5, 5), puzzle("What is 2 + 2?", "4") {}

void Game::start() {
    maze.displayMaze();
    char move;
    while (true) {
        std::cout << "Enter move (WASD): ";
        std::cin >> move;
        handlePlayerMove(move);
        checkGameState();
    }
}

void Game::handlePlayerMove(char move) {
    player.move(move);
    player.displayPosition();
    // Add collision detection and game logic here
}

void Game::checkGameState() {
    // Check if player reached exit or encountered enemy
    if (player.getX() == 8 && player.getY() == 8) {
        std::cout << "You've reached the exit! You win!" << std::endl;
        exit(0);
    }
    // Add more game state checks as needed
}
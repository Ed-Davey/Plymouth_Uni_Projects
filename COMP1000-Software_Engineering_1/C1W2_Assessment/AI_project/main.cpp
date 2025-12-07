#include "include/MazeGeneration.h"  // Include the MazeGeneration header for Position
#include "include/PlayerMovement.h"
#include "include/Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

int main() {
    std::srand(std::time(nullptr));

    MazeGenerator maze(21, 21);
    maze.generate();

    Player player(1, 1);

    // Number of enemies to add
    const int numEnemies = 10;  // Adjust this number to make the game more challenging
    std::vector<Enemy> enemies;

    // Random number generator for enemy placement
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> dist(1, maze.getWidth() - 2);

    // Create enemies and place them randomly in the maze
    for (int i = 0; i < numEnemies; ++i) {
        int x = dist(rng);
        int y = dist(rng);

        // Ensure enemies don't spawn on the player or walls
        while (maze.getMaze()[y][x] == '#' || (x == player.getPosition().x && y == player.getPosition().y)) {
            x = dist(rng);
            y = dist(rng);
        }

        enemies.push_back(Enemy(x, y));
    }

    char input;
    while (true) {
        // Platform-specific screen clearing
        #ifdef _WIN32
            system("cls"); // Windows-specific
        #else
            system("clear"); // Unix/Linux/MacOS
        #endif

        // Render maze with player and enemies
        maze.renderWithPlayer(player.getPosition(), enemies);

        // Get player input and validate it
        std::cout << "Move (W/A/S/D): ";
        std::cin >> input;

        // Ensure valid input
        if (input != 'W' && input != 'A' && input != 'S' && input != 'D') {
            std::cout << "Invalid input! Use W/A/S/D to move.\n";
            continue; // Skip the rest of the loop
        }

        // Move player
        if (!player.move(input, maze.getMaze())) {
            std::cout << "You can't move there!\n";
        }

        // Move enemies
        for (auto& enemy : enemies) {
            enemy.move(maze.getMaze());
        }

        // Check if player is caught by any enemy
        for (auto& enemy : enemies) {
            if (player.getPosition().x == enemy.getPosition().x &&
                player.getPosition().y == enemy.getPosition().y) {
                std::cout << "You were caught by an enemy! Game Over!\n";
                return 0;  // Exit the game
            }
        }

        // Optional: Add a win condition (e.g., reaching a goal position)
    }

    return 0;
}

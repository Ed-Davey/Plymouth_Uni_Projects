// MazeGeneration.h
#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <vector>
#include "Position.h"  // Include Position.h to use Position
#include "Enemy.h"  // Ensure this is included at the top of any file using Enemy


class MazeGenerator {
public:
    MazeGenerator(int width, int height);
    void generate();
    void renderWithPlayer(const Position& playerPos, const std::vector<Enemy>& enemies) const;
    const std::vector<std::vector<char>>& getMaze() const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width, height;
    std::vector<std::vector<char>> maze;

    void carvePath(int x, int y);
};

#endif // MAZEGENERATOR_H

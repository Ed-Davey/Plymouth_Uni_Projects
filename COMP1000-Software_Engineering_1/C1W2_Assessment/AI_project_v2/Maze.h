#ifndef MAZE_H
#define MAZE_H

#include <vector>

class Maze {
public:
    Maze(int width, int height);
    void generateMaze();
    void displayMaze();
    char getCell(int x, int y); // Get the cell type at (x, y)
    void setCell(int x, int y, char value); // Set the cell type at (x, y)

private:
    int width, height;
    std::vector<std::vector<char>> maze;
};

#endif // MAZE_H
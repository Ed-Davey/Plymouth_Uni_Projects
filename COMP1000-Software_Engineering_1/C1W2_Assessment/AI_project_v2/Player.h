#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int startX, int startY);
    void move(char direction);
    void displayPosition();
    int getX() const; // Get player's X position
    int getY() const; // Get player's Y position

private:
    int x, y;
};

#endif // PLAYER_H
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int startX, int startY);
    void move(); // Define enemy movement logic
    void displayPosition();
    int getX() const; // Get enemy's X position
    int getY() const; // Get enemy's Y position

private:
    int x, y;
};

#endif // ENEMY_H
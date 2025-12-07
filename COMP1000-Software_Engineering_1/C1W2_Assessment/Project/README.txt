Welcome to the Mystery Maze!

In this game, you need to navigate your way through a randomly generated maze avoiding enemies along the way.

How to play
-Use the Project executable file open it in the terminal to play the game
-To control the player you will need to use the W/A/S/D keys
    W for up
    A for left
    S for down
    D for right
-Your objective is to go to the key icon in the top right, answer a riddle correctly, and then go to the lock icon in the bottom right while avoiding the enemies.
-You will have a different number of lives depending on the difficulty selected:
    5 lives for Easy
    3 lives for Medium
    1 life for Hard

Maze Generation
-The maze is represented by a 21x21 grid made up of black and white tiles. The maze is carved using the carve_maze function which uses recursive backtracking to remove walls (⬛️) and replace them with path tiles (⬜️)
-The player is placed in the top left, key in the top right and the lock on the bottom right.

Additional features
-When you reach the key you have to answer 1 of 16 randomly picked different riddles which you have 3 attempts to answer (after you get one wrong the riddle changes) before it's game over.
-There are 5 enemies that move randomly around the maze trying to take lives off you before you can reach the end.
-The maze is printed to the terminal after every player move. This shows the location of the player, enemies, key and lock.

Troubleshooting
-If you are having issues running the game, ensure that you are using the MacOS operating system and trying to open the Project executable in the terminal.
-You must be using MacOS when running this program as it doesn't work on windows or other operating systems.
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

#define SIZE_OF_MAZE 21
int playerX, playerY, lives;
int alien1X, alien1Y, alien2X, alien2Y, alien3X, alien3Y, alien4X, alien4Y, alien5X, alien5Y;
int alien1Dir, alien2Dir, alien3Dir, alien4Dir, alien5Dir = -1;
bool Has_Key = false;

std::string array [SIZE_OF_MAZE][SIZE_OF_MAZE];

int player_movement(int* playerX,int* playerY, int* lives, bool* Has_Key);
void title_screen(int* lives);
bool riddle(bool* Has_Key);
void generate_maze(std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
void carve_maze(std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], int x, int y, const int dx[], const int dy[]);
void alien1_spawn(int* alien1X, int* alien1Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
int alien1_move(int* playerX,int* playerY,int* lives, int* alien1X, int* alien1Y, int* alien1Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key);
void alien2_spawn(int* alien2X, int* alien2Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
int alien2_move(int* playerX,int* playerY,int* lives, int* alien2X, int* alien2Y, int* alien2Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key);
void alien3_spawn(int* alien3X, int* alien3Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
int alien3_move(int* playerX,int* playerY,int* lives, int* alien3X, int* alien3Y, int* alien3Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key);
void alien4_spawn(int* alien4X, int* alien4Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
int alien4_move(int* playerX,int* playerY,int* lives, int* alien4X, int* alien4Y, int* alien4Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key);
void alien5_spawn(int* alien5X, int* alien5Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]);
int alien5_move(int* playerX,int* playerY,int* lives, int* alien5X, int* alien5Y, int* alien5Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key);

int main(){
    //maze generation
    for (int i=0; i<SIZE_OF_MAZE; i++) {
        for (int j=0; j<SIZE_OF_MAZE; j++) {
            array[i][j] = "⬛";
        }
    }

    playerX = playerY = 1;

    title_screen(&lives);

    generate_maze(array);

    alien1_spawn(&alien1X, &alien1Y, array);
    alien2_spawn(&alien2X, &alien2Y, array);
    alien3_spawn(&alien3X, &alien3Y, array);
    alien4_spawn(&alien4X, &alien4Y, array);
    alien5_spawn(&alien5X, &alien5Y, array);

    for (int i=0; i<SIZE_OF_MAZE; i++) {
        for (int j=0; j<SIZE_OF_MAZE; j++) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }

    while (!(playerX == 19 && playerY == 19 && Has_Key)){

        player_movement(&playerX, &playerY, &lives, &Has_Key);
        alien1_move(&playerX, &playerY, &lives, &alien1X, &alien1Y, &alien1Dir, array, &Has_Key);
        alien2_move(&playerX, &playerY, &lives, &alien2X, &alien2Y, &alien2Dir, array, &Has_Key);
        alien3_move(&playerX, &playerY, &lives, &alien3X, &alien3Y, &alien3Dir, array, &Has_Key);
        alien4_move(&playerX, &playerY, &lives, &alien4X, &alien4Y, &alien4Dir, array, &Has_Key);
        alien5_move(&playerX, &playerY, &lives, &alien5X, &alien5Y, &alien5Dir, array, &Has_Key);

        if (lives <= 0) {
            std::cout << "Number of lives remaining: " << lives << std::endl; //output how many lives the user has left
            std::cout << "GAME OVER!" << std::endl;
            return 0;
        }

        //print maze
        for (int i=0; i<SIZE_OF_MAZE; i++) {
            for (int j=0; j<SIZE_OF_MAZE; j++) {
                std::cout << array[i][j];
            }
            std::cout << std::endl;
        }

        std::cout << "Player Position: (" << playerX << ", " << playerY << ")" << std::endl;

        if (playerX == 1 && playerY == 19) {
            riddle(&Has_Key);
            if (Has_Key == false) {
                std::cout << "GAME OVER!" << std::endl;
                return 0;
            } else if (Has_Key == true) {
                array [19][19] = "🔐";
                std::cout << "Next area unlocked" << std::endl;

                //print maze
                for (int i=0; i<SIZE_OF_MAZE; i++) {
                    for (int j=0; j<SIZE_OF_MAZE; j++) {
                        std::cout << array[i][j];
                    }
                    std::cout << std::endl;
                }

            }
        }
    }

    std::cout << "Congratulations! You beat the maze!" << std::endl;

    return 0;
}

void title_screen(int* lives) {
    bool valid_input = false;
    std::string input;
    std::cout << "\nWelcome to the maze game!" << std::endl << std::endl;

    std::cout << "Objectives:\n- Move to the key icon (🔑) and solve a riddle.\n- If you answer correctly, proceed to the lock icon tile (🔒 or 🔐).\n- Avoid enemies (👾) trying to stop you!" << std::endl << std::endl;

    std::cout << "How to play:\n- Use the w/a/s/d keys to move your character around the maze." << std::endl << std::endl;

    std::cout << "Key:\n- The black tiles (⬛️) indicate the maze walls.\n- The white tiles (⬜️) indicate the path you, and the enemies, will follow.\n- The enemies (👾) will be trying to catch you and stop you from completing the maze.\n- The key (🔑) represents where you will go to answer the riddle.\n- The lock (🔒 or 🔐) represents the end of the maze.\n\nIf only the lock is displayed, you need to go to the key tile to obtain it.\nIf the key is displayed alongside the lock, you have answered the riddle correctly and can proceed to beat the maze.\n\nIf you are caught by the enemies (👾), you will lose a life. The number of lives you have depends on the difficulty level.\n- Easy 5 lives\n- Medium 3 lives\n- Hard 1 life\nBe extra careful, as once you run out of lives, it’s game over!" << std::endl << std::endl;

    while (valid_input != true)
        {
        std::cout << "Select difficulty level Easy (E), Medium (M), Hard (H): ";
        std::cin >> input;
        std::cout << std::endl;

        if (input == "E" || input == "e") {
            *lives = 5;
            valid_input = true;
        } else if (input == "M" || input == "m") {
            *lives = 3;
            valid_input = true;
        } else if (input == "H" || input == "h") {
            *lives = 1;
            valid_input = true;
        }else {
            std::cout << "ERROR: Please enter E, M or H. 'E' for easy,'M' for medium and 'H' for hard" << std::endl << std::endl;
        }
    }
}

int player_movement(int* playerX,int* playerY, int* lives, bool* Has_Key) {
    int changeX = *playerX, changeY = *playerY; //initialise the variables
    std::cout << "Number of lives remaining: " << *lives << std::endl; //output how many lives the user has left
    std::cout << "Move player by using W/A/S/D: "; //outputted to screen
    std::string input_verify; //initialise string for input of more than one character
    std::cin >> input_verify; //read user input
    char input = input_verify[0]; //take only first character

    switch (input) {
        case 'W': case 'w': {
            changeX = *playerX-1;
            std::cout << "up\n";
            break;
        }
        case 'S': case 's': {
            changeX = *playerX+1;
            std::cout << "down\n";
            break;
        }
        case 'A': case 'a': {
            changeY = *playerY-1;
            std::cout << "left\n";
            break;
        }
        case 'D': case 'd': {
            changeY = *playerY+1;
            std::cout << "right\n";
            break;
        }
        default: {
            std::cout << "ERROR: Invalid input" << std::endl;
            return 1;
        }
    }

    if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
        if (*playerX == 19 && *playerY == 19 && *Has_Key == false) {
            array[*playerX][*playerY] = "🔒";
        } else if (*playerX == 19 && *playerY == 19 && *Has_Key == true) {
            array[*playerX][*playerY] = "🔐";
        } else {
            array[*playerX][*playerY] = "⬜️";
        }
        *playerX = changeX;
        *playerY = changeY;
        array[*playerX][*playerY] = "😀";
    }else {
        std::cout << "ERROR: Invalid input" << std::endl;
    }

    return 0;
}

bool riddle(bool* Has_Key) {
    int attempts = 3;
    std::string answer, reply;
    bool ready = false;

    while (ready == false) {
        std::cout << "Are you ready to face the riddles?" << std::endl;
        std::cin >> reply;
        if (reply == "yes") {
            ready = true;
        } else {std::cout << "type 'yes' when you are ready";}
    }

    std::cin.ignore();

    while (attempts != 0) {
        int random_num = rand() % 16;
        //int random_num = 0;

        //std::cout << random_num << std::endl;
        switch (random_num) {
            case 0: {
                std::cout << "What has keys but can't open locks?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "piano") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 1: {
                std::cout << "I shave everyday but my beard remains the same length. what am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "a barber" || answer == "barber") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 2: {
                std::cout << "I speak without a mouth and hear without ears.\nI have no body, but I come alive with the wind. What am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "an echo" || answer == "echo") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 3: {
                std::cout << "What begins with T, ends with T, and has T in it?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "teapot" || answer == "a teapot") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 4: {
                std::cout << "I can fly without wings. I can cry without eyes.\nWherever I go, darkness follows me. What am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "cloud" || answer == "a cloud") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 5: {
                std::cout << "What has a neck but no head?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "bottle" || answer == "a bottle") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 6: {
                std::cout << "The more you take, the more you leave behind. What am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "footsteps") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 7: {
                std::cout << "What can travel around the world while staying in a corner?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "stamp" || answer == "a stamp") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 8: {
                std::cout << "What has many teeth but cannot bite?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "comb" || answer == "a comb" || answer == "gear" || answer == "a gear" || answer == "gears" || answer == "zip" || answer == "a zip") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 9: {
                std::cout << "I have branches, but no fruit, trunk, or leaves. What am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "bank" || answer == "a bank") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 10: {
                std::cout << "What can you catch but not throw?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "cold" || answer == "a cold") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 11: {
                std::cout << "What has a head and a tail but no body?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "coin" || answer == "a coin" || answer == "coins") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 12: {
                std::cout << "I am not alive, but I can grow.\nI don’t have lungs, but I need air.\nI don’t have a mouth, but water kills me. What am I?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "fire" || answer == "a fire") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 13: {
                std::cout << "What is always in front of you but can’t be seen?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "the future") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 14: {
                std::cout << "What has one eye but cannot see?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "needle" || answer == "a needle") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            case 15: {
                std::cout << "What gets wetter as it dries?" << std::endl;
                std::getline(std::cin, answer);
                if (answer == "towel" || answer == "a towel") {
                    *Has_Key = true;
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect answer" << std::endl;
                    attempts--;
                    std::cout << "Number of attempts left: " << attempts << std::endl << std::endl;
                    break;
                }
            }
            default: {
                std::cout << "ERROR!" << std::endl;
            }
        }

        if (*Has_Key == true) {
            break;
        }
    }
    return false;
}

void generate_maze(std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {// Initialize the maze with walls

    // Define directions (up, down, left, right)
    const int directionX[] = {0, 0, -2, 2}; // Changes in x-coordinates
    const int directionY[] = {-2, 2, 0, 0}; // Changes in y-coordinates

    // Start carving from the player's starting position
    array[1][1] = "⬜"; // Start cell
    carve_maze(array, 1, 1, directionX, directionY);

    // Add player start position
    array[1][1] = "😀";

    // Add key square
    array[1][SIZE_OF_MAZE - 2] = "🔑";

    // Add finish square
    array[SIZE_OF_MAZE - 2][SIZE_OF_MAZE - 2] = "🔒";
}

void carve_maze(std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], int x, int y, const int directionX[], const int directionY[]) {
    // Shuffle directions to ensure randomness
    std::vector<int> directions = {0, 1, 2, 3};
    std::random_device random;
    std::mt19937 generator(random());
    std::shuffle(directions.begin(), directions.end(), generator);

    for (int move : directions) {
        int nx = x + directionX[move]; // New x
        int ny = y + directionY[move]; // New y

        // Check bounds and if the next cell is already visited
        if (nx > 0 && ny > 0 && nx < SIZE_OF_MAZE - 1 && ny < SIZE_OF_MAZE - 1 &&
            array[nx][ny] == "⬛") {
            // Carve a pathway
            array[nx][ny] = "⬜"; // Current cell
            array[x + directionX[move] / 2][y + directionY[move] / 2] = "⬜"; // Path between cells
            carve_maze(array, nx, ny, directionX, directionY); // Recurse
            }
    }
}

void alien1_spawn(int *alien1X, int *alien1Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {
    bool alien_spawned = false;

    while (alien_spawned == false) {
        int randomX = (rand() % (SIZE_OF_MAZE-2) + 1);
        int randomY = (rand() % (SIZE_OF_MAZE-2) + 1);
        //int randomX = 1;
        //int randomY = 2;

        std::string comparison = array[randomX][randomY];

        //std::cout << comparison << array[randomX][randomY] << std::endl;

        if (comparison == "⬜") {
            *alien1X = randomX;
            *alien1Y = randomY;
            array[*alien1X][*alien1Y] = "👾";

            alien_spawned = true;
        }
    }
}

int alien1_move(int *playerX, int *playerY, int *lives, int *alien1X, int *alien1Y, int* alien1Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key) {
    int changeX = *alien1X, changeY = *alien1Y; //initialise the variables
    bool alien1Moved = false;

    while (alien1Moved == false) {

        if (*alien1Dir == -1) {
            *alien1Dir = rand() % 4;
        }

        switch (*alien1Dir) {
            case 0:{
                changeX = *alien1X-1;
                //std::cout << "up\n";
                break;
            }
            case 1:{
                changeX = *alien1X+1;
                //std::cout << "down\n";
                break;
            }
            case 2:{
                changeY = *alien1Y-1;
                //std::cout << "left\n";
                break;
            }
            case 3:{
                changeY = *alien1Y+1;
                //std::cout << "right\n";
                break;
            }
            default: {
                //std::cerr << "Invalid input" << std::endl;
                return 1;
            }
        }

        if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
            if (*alien1X == 19 && *alien1Y == 19 && *Has_Key == false) {
                array[*alien1X][*alien1Y] = "🔒";
            } else if (*alien1X == 19 && *alien1Y == 19 && *Has_Key == true) {
                array[*alien1X][*alien1Y] = "🔐";
            } else if (*alien1X == 1 && *alien1Y == 19 && *Has_Key == false) {
                array[*alien1X][*alien1Y] = "🔑";
            } else if (*playerX == *alien1X && *playerY == *alien1Y) {
                array[*alien1X][*alien1Y] = "😀";
            } else {
                array[*alien1X][*alien1Y] = "⬜️";
            }
            *alien1X = changeX;
            *alien1Y = changeY;
            array[*alien1X][*alien1Y] = "👾";
            alien1Moved = true;
        }else {
            //std::cout << "ERROR: Invalid input" << std::endl;
            changeX = *alien1X;
            changeY = *alien1Y;
            *alien1Dir = -1;
        }
    }

    if (*playerX == *alien1X && *playerY == *alien1Y) {
        std::cout << "You have been caught by the alien" << std::endl;
        (*lives) --;
    }

    return 0;
}

void alien2_spawn(int *alien2X, int *alien2Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {
    bool alien_spawned = false;

    while (alien_spawned == false) {
        int randomX = (rand() % (SIZE_OF_MAZE-2) + 1);
        int randomY = (rand() % (SIZE_OF_MAZE-2) + 1);
        //int randomX = 1;
        //int randomY = 2;

        std::string comparison = array[randomX][randomY];

        //std::cout << comparison << array[randomX][randomY] << std::endl;

        if (comparison == "⬜") {
            *alien2X = randomX;
            *alien2Y = randomY;
            array[*alien2X][*alien2Y] = "👾";

            alien_spawned = true;
        }
    }
}

int alien2_move(int *playerX, int *playerY, int *lives, int *alien2X, int *alien2Y, int *alien2Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key) {
    int changeX = *alien2X, changeY = *alien2Y; //initialise the variables
    bool alien1Moved = false;

    while (alien1Moved == false) {

        if (*alien2Dir == -1) {
            *alien2Dir = rand() % 4;
        }

        switch (*alien2Dir) {
            case 0:{
                changeX = *alien2X-1;
                //std::cout << "up\n";
                break;
            }
            case 1:{
                changeX = *alien2X+1;
                //std::cout << "down\n";
                break;
            }
            case 2:{
                changeY = *alien2Y-1;
                //std::cout << "left\n";
                break;
            }
            case 3:{
                changeY = *alien2Y+1;
                //std::cout << "right\n";
                break;
            }
            default: {
                //std::cerr << "Invalid input" << std::endl;
                return 1;
            }
        }

        if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
            if (*alien2X == 19 && *alien2Y == 19 && *Has_Key == false) {
                array[*alien2X][*alien2Y] = "🔒";
            } else if (*alien2X == 19 && *alien2Y == 19 && *Has_Key == true) {
                array[*alien2X][*alien2Y] = "🔐";
            } else if (*alien2X == 1 && *alien2Y == 19 && *Has_Key == false) {
                array[*alien2X][*alien2Y] = "🔑";
            } else if (*playerX == *alien2X && *playerY == *alien2Y) {
                array[*alien2X][*alien2Y] = "😀";
            } else {
                array[*alien2X][*alien2Y] = "⬜️";
            }
            *alien2X = changeX;
            *alien2Y = changeY;
            array[*alien2X][*alien2Y] = "👾";
            alien1Moved = true;
        }else {
            //std::cout << "ERROR: Invalid input" << std::endl;
            changeX = *alien2X;
            changeY = *alien2Y;
            *alien2Dir = -1;
        }
    }

    if (*playerX == *alien2X && *playerY == *alien2Y) {
        std::cout << "You have been caught by the alien" << std::endl;
        (*lives) --;
    }

    return 0;
}

void alien3_spawn(int *alien3X, int *alien3Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {
    bool alien_spawned = false;

    while (alien_spawned == false) {
        int randomX = (rand() % (SIZE_OF_MAZE-2) + 1);
        int randomY = (rand() % (SIZE_OF_MAZE-2) + 1);
        //int randomX = 1;
        //int randomY = 2;

        std::string comparison = array[randomX][randomY];

        //std::cout << comparison << array[randomX][randomY] << std::endl;

        if (comparison == "⬜") {
            *alien3X = randomX;
            *alien3Y = randomY;
            array[*alien3X][*alien3Y] = "👾";

            alien_spawned = true;
        }
    }
}

int alien3_move(int *playerX, int *playerY, int *lives, int *alien3X, int *alien3Y, int *alien3Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key) {
    int changeX = *alien3X, changeY = *alien3Y; //initialise the variables
    bool alien1Moved = false;

    while (alien1Moved == false) {

        if (*alien3Dir == -1) {
            *alien3Dir = rand() % 4;
        }

        switch (*alien3Dir) {
            case 0:{
                changeX = *alien3X-1;
                //std::cout << "up\n";
                break;
            }
            case 1:{
                changeX = *alien3X+1;
                //std::cout << "down\n";
                break;
            }
            case 2:{
                changeY = *alien3Y-1;
                //std::cout << "left\n";
                break;
            }
            case 3:{
                changeY = *alien3Y+1;
                //std::cout << "right\n";
                break;
            }
            default: {
                //std::cerr << "Invalid input" << std::endl;
                return 1;
            }
        }

        if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
            if (*alien3X == 19 && *alien3Y == 19 && *Has_Key == false) {
                array[*alien3X][*alien3Y] = "🔒";
            } else if (*alien3X == 19 && *alien3Y == 19 && *Has_Key == true) {
                array[*alien3X][*alien3Y] = "🔐";
            } else if (*alien3X == 1 && *alien3Y == 19 && *Has_Key == false) {
                array[*alien3X][*alien3Y] = "🔑";
            } else if (*playerX == *alien3X && *playerY == *alien3Y) {
                array[*alien3X][*alien3Y] = "😀";
            } else {
                array[*alien3X][*alien3Y] = "⬜️";
            }
            *alien3X = changeX;
            *alien3Y = changeY;
            array[*alien3X][*alien3Y] = "👾";
            alien1Moved = true;
        }else {
            //std::cout << "ERROR: Invalid input" << std::endl;
            changeX = *alien3X;
            changeY = *alien3Y;
            *alien3Dir = -1;
        }
    }

    if (*playerX == *alien3X && *playerY == *alien3Y) {
        std::cout << "You have been caught by the alien" << std::endl;
        (*lives) --;
    }

    return 0;
}

void alien4_spawn(int *alien4X, int *alien4Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {
    bool alien_spawned = false;

    while (alien_spawned == false) {
        int randomX = (rand() % (SIZE_OF_MAZE-2) + 1);
        int randomY = (rand() % (SIZE_OF_MAZE-2) + 1);
        //int randomX = 1;
        //int randomY = 2;

        std::string comparison = array[randomX][randomY];

        //std::cout << comparison << array[randomX][randomY] << std::endl;

        if (comparison == "⬜") {
            *alien4X = randomX;
            *alien4Y = randomY;
            array[*alien4X][*alien4Y] = "👾";

            alien_spawned = true;
        }
    }
}

int alien4_move(int *playerX, int *playerY, int *lives, int *alien4X, int *alien4Y, int *alien4Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key) {
    int changeX = *alien4X, changeY = *alien4Y; //initialise the variables
    bool alien1Moved = false;

    while (alien1Moved == false) {

        if (*alien4Dir == -1) {
            *alien4Dir = rand() % 4;
        }

        switch (*alien4Dir) {
            case 0:{
                changeX = *alien4X-1;
                //std::cout << "up\n";
                break;
            }
            case 1:{
                changeX = *alien4X+1;
                //std::cout << "down\n";
                break;
            }
            case 2:{
                changeY = *alien4Y-1;
                //std::cout << "left\n";
                break;
            }
            case 3:{
                changeY = *alien4Y+1;
                //std::cout << "right\n";
                break;
            }
            default: {
                //std::cerr << "Invalid input" << std::endl;
                return 1;
            }
        }

        if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
            if (*alien4X == 19 && *alien4Y == 19 && *Has_Key == false) {
                array[*alien4X][*alien4Y] = "🔒";
            } else if (*alien4X == 19 && *alien4Y == 19 && *Has_Key == true) {
                array[*alien4X][*alien4Y] = "🔐";
            } else if (*alien4X == 1 && *alien4Y == 19 && *Has_Key == false) {
                array[*alien4X][*alien4Y] = "🔑";
            } else if (*playerX == *alien4X && *playerY == *alien4Y) {
                array[*alien4X][*alien4Y] = "😀";
            } else {
                array[*alien4X][*alien4Y] = "⬜️";
            }
            *alien4X = changeX;
            *alien4Y = changeY;
            array[*alien4X][*alien4Y] = "👾";
            alien1Moved = true;
        }else {
            //std::cout << "ERROR: Invalid input" << std::endl;
            changeX = *alien4X;
            changeY = *alien4Y;
            *alien4Dir = -1;
        }
    }

    if (*playerX == *alien4X && *playerY == *alien4Y) {
        std::cout << "You have been caught by the alien" << std::endl;
        (*lives) --;
    }

    return 0;
}

void alien5_spawn(int *alien5X, int *alien5Y, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE]) {
    bool alien_spawned = false;

    while (alien_spawned == false) {
        int randomX = (rand() % (SIZE_OF_MAZE-2) + 1);
        int randomY = (rand() % (SIZE_OF_MAZE-2) + 1);
        //int randomX = 1;
        //int randomY = 2;

        std::string comparison = array[randomX][randomY];

        //std::cout << comparison << array[randomX][randomY] << std::endl;

        if (comparison == "⬜") {
            *alien5X = randomX;
            *alien5Y = randomY;
            array[*alien5X][*alien5Y] = "👾";

            alien_spawned = true;
        }
    }
}

int alien5_move(int *playerX, int *playerY, int *lives, int *alien5X, int *alien5Y, int *alien5Dir, std::string (&array)[SIZE_OF_MAZE][SIZE_OF_MAZE], bool* Has_Key) {
    int changeX = *alien5X, changeY = *alien5Y; //initialise the variables
    bool alien1Moved = false;

    while (alien1Moved == false) {

        if (*alien5Dir == -1) {
            *alien5Dir = rand() % 4;
        }

        switch (*alien5Dir) {
            case 0:{
                changeX = *alien5X-1;
                //std::cout << "up\n";
                break;
            }
            case 1:{
                changeX = *alien5X+1;
                //std::cout << "down\n";
                break;
            }
            case 2:{
                changeY = *alien5Y-1;
                //std::cout << "left\n";
                break;
            }
            case 3:{
                changeY = *alien5Y+1;
                //std::cout << "right\n";
                break;
            }
            default: {
                //std::cerr << "Invalid input" << std::endl;
                return 1;
            }
        }

        if (changeX > 0 && changeX < (SIZE_OF_MAZE-1) && changeY > 0 && changeY < (SIZE_OF_MAZE-1) && array[changeX][changeY] != "⬛") {
            if (*alien5X == 19 && *alien5Y == 19 && *Has_Key == false) {
                array[*alien5X][*alien5Y] = "🔒";
            } else if (*alien5X == 19 && *alien5Y == 19 && *Has_Key == true) {
                array[*alien5X][*alien5Y] = "🔐";
            } else if (*alien5X == 1 && *alien5Y == 19 && *Has_Key == false) {
                array[*alien5X][*alien5Y] = "🔑";
            } else if (*playerX == *alien5X && *playerY == *alien5Y) {
                array[*alien5X][*alien5Y] = "😀";
            } else {
                array[*alien5X][*alien5Y] = "⬜️";
            }
            *alien5X = changeX;
            *alien5Y = changeY;
            array[*alien5X][*alien5Y] = "👾";
            alien1Moved = true;
        }else {
            //std::cout << "ERROR: Invalid input" << std::endl;
            changeX = *alien5X;
            changeY = *alien5Y;
            *alien5Dir = -1;
        }
    }

    if (*playerX == *alien5X && *playerY == *alien5Y) {
        std::cout << "You have been caught by the alien" << std::endl;
        (*lives) --;
    }

    return 0;
}







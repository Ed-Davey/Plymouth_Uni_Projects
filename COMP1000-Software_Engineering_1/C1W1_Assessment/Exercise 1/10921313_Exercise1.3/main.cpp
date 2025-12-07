#include <iostream> //this allows for input and output within the program

int main() {

    for (int i = 1; i <= 10; i++) { //this will start a for loop that initialises an integer variable i as 1 then for every time the code restarts adds one until it reaches 10
        std::cout << i << std::endl; //this will print the value currently within i to the users screen
    } //this shows where the end of the executed code within the for loop
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

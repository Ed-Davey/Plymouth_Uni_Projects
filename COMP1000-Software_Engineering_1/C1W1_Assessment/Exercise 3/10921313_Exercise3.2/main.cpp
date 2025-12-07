#include <iostream> //this allows for input and output within the program

void counter() { //this creates a function called counter() with no return (void)
    static int counter = 0; //this creates a static integer called counter with the value 0
    counter++; //this adds 1 to the value in counter
    std::cout << "This function has been called " << counter << " times" << std::endl; //this will show "This function has been called " on the screen followed by the value within the counter variable followed by " times"
}

int main()
{
    counter(); //this calls the counter function
    counter(); //this calls the counter function
    counter(); //this calls the counter function
    counter(); //this calls the counter function
    counter(); //this calls the counter function

    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

#include <iostream> //this allows for input and output within the program

int main() {
    int number; //this declares the variable number as an integer

    std::cout << "Enter a number: "; //This will print a message on the users screen
    std::cin >> number; //This will take what is typed on the keyboard and save it in the variable number

    if (number % 2 == 0) { //this will check to see if the number divided by 2 has the remainder of 0
        std::cout << number << " is even\n"; //this prints the number and that it is even on the users screen
    } else if (number % 2 == 1) { //this will check to see if the number divided by 2 has the remainder of 1
        std::cout << number << " is odd\n"; //this prints the number and that it is odd on the users screen
    } else { //this will execute if the other two options don't occur
        std::cerr << "ERROR!\n"; //This will print that there was an error on the users screen
    }
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

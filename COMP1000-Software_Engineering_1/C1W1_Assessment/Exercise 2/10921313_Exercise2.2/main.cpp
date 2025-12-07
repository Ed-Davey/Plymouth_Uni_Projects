#include <iostream> //this allows for input and output within the program

int main()
{
    int day; //this declares the variable day as an integer

    std::cout << "Enter a number 1-7: "; //This will print a message on the users screen
    std::cin >> day; //This will take what is typed on the keyboard and save it in the variable day

    switch (day){ //this will begin a switch statement checking the values within the day variable

        case 1: //this will execute if the number inside the day variable equals 1
            std::cout << "Sunday" << std::endl; //this will print "Sunday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 2: //this will execute if the number inside the day variable equals 2
            std::cout << "Monday" << std::endl; //this will print "Monday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 3: //this will execute if the number inside the day variable equals 3
            std::cout << "Tuesday" << std::endl; //this will print "Tuesday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 4: //this will execute if the number inside the day variable equals 4
            std::cout << "Wednesday" << std::endl; //this will print "Wednesday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 5: //this will execute if the number inside the day variable equals 5
            std::cout << "Thursday" << std::endl; //this will print "Thursday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 6: //this will execute if the number inside the day variable equals 6
            std::cout << "Friday" << std::endl; //this will print "Friday" on the users screen
            break; //this tells the program to break out of the switch statement

        case 7: //this will execute if the number inside the day variable equals 7
            std::cout << "Saturday" << std::endl; //this will print "Saturday" on the users screen
            break; //this tells the program to break out of the switch statement

        default: //this will execute if the number inside the day variable isn't any of the cases
            std::cerr << "Invalid input" << std::endl; //this will print an error message with "Invalid input" on the users screen
    }
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

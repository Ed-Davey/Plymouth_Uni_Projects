#include <iostream> //this allows for input and output within the program

int main()
{
    int numbers [5] = {5,10,15,20,25}; //this initializes an integer array called numbers with the values 5,10,15,20,25

    std::cout << "The third element of the array is " << numbers[2] << std::endl; //this will get the third element from the array and print it on the users screen after the text "The third element of the array is "
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

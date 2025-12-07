#include <iostream> //this allows for input and output within the program

int main()
{
    int num1 = 5; //this stores the value 5 in the variable num1 which is in integer
    int num2 = 3; //this stores the value 3 in the variable num2 which is in integer

    int product = num1 * num2; //this multiplies the values within num1 and num2 and stores then in an integer variable called product

    std::cout << "The product of the numbers are: " << product << std::endl; //this prints "The product of the numbers are:" and then the number stored in product on the users screen
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

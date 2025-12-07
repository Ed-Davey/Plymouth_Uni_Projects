#include <iostream> //this allows for input and output within the program

int main()
{
    int num1 = 10; //this stores the value 10 in the variable num1 which is in integer
    int num2 = 15; //this stores the value 15 in the variable num2 which is in integer

    int sum = num1 + num2; //this adds the values within num1 and num2 and stores then in an integer variable called sum

    std::cout << "The sum of the numbers are: " << sum << std::endl; //this prints "The sum of the numbers are:" and then the number stored in sum on the users screen
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

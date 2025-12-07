#include <iostream> //this allows for input and output within the program

int globalNum = 0; //define a global variable called globalNum of type integer with the value 0
static int staticGlobalNum = 0; //define a static global variable called staticGlobalNum of type integer with the value 0

void variableChange() { //this creates a function called variableChange() with no return (void)
    staticGlobalNum ++; //this adds 1 to the value in staticGlobalNum
    globalNum ++; //this adds 1 to the value in globalNum
    std::cout << "static global number: " << staticGlobalNum << ", global number: " << globalNum << std::endl; //this will show "static global number: " followed by the value within staticGlobalNum followed by ", global number: " followed by the value within globalNum on the users screen
}
int main()
{
    variableChange(); //this calls the variableChange function
    variableChange(); //this calls the variableChange function
    variableChange(); //this calls the variableChange function
    variableChange(); //this calls the variableChange function
    variableChange(); //this calls the variableChange function

    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}

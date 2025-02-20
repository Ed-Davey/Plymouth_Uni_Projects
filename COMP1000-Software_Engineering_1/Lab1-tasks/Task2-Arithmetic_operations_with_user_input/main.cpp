#include <iostream>
using namespace std;

int main()
{
    //initialise values
    int num1 = 0;
    int num2 = 0;

    //input first number
    cout << "Enter a number: ";
    cin >> num1;

    //input second number
    cout << "Enter another number: " ;
    cin >> num2;

    //arithmitic
    int add = num1 + num2;
    int sub = num1 - num2;
    int mul = num1 * num2;
    float div = float(num1) / float(num2);
    int mod = num1 % num2;

    //output results
    cout << "Addition: " << add << endl << "Subtraction: " << sub << endl << "Multiplication: " << mul << endl << "Division: " << div << endl << "Modulus: " << mod << endl;

    return 0;
}

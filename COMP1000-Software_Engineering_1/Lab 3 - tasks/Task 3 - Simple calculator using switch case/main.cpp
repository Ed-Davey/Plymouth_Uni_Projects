#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    char sign;
    int num1, num2, total;
    bool valid_input = false;

    do {
        cout << "Do you want to do addition (+), subtraction (-), multiplication (*) or division (/)? ";
        cin >> input;
        if (input == "+"|| input == "-" || input == "*" || input == "/") {
            valid_input = true;
            sign = input[0];
        } else {
            cout << "Please enter a valid input." << endl << endl;
        }
    }
    while (valid_input == false);

    cout << "\nEnter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    switch (sign) {
        case '+':
            total = num1 + num2;

            cout << "\nThe answer is " << total << endl;

            break;

        case '-':
            total = num1 - num2;

            cout << "\nThe answer is " << total << endl;

            break;

        case '*':
            total = num1 * num2;

            cout << "\nThe answer is " << total << endl;

            break;

        case '/':
            total = num1 / num2;

            cout << "\nThe answer is " << total << endl;

            break;

        default:
            cout << "ERROR! Invalid Input!";
    }


    return 0;
}

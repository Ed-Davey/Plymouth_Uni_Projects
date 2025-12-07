#include <iostream>
using namespace std;

int num1 = 5;
int num2 = 3;
int sum;

void addTwoNumbers(int num1, int num2)
{
    sum = num1 + num2;
    cout << "\nTotal: " << sum << endl;
}


int main()
{
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;

    addTwoNumbers(num1, num2);



    return 0;
}

#include <iostream>
#include <string>
#include "main.h"
using namespace std;

int main()
{
    Box<int>intBox(10);
    Box<double>doubleBox(25.5);
    Box<string>stringBox("Hello");

    cout << "Box value (int): " << intBox.getValue() << endl;
    cout << "Box value (double): " << doubleBox.getValue() << endl;
    cout << "Box value (string): " << stringBox.getValue() << endl;

    return 0;
}

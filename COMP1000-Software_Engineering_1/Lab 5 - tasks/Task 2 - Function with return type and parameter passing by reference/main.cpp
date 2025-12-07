#include <iostream>
using namespace std;

int a = 5;
int b = 3;

void swapnumber(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;

    cout << "\nWithin the function\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

int main() {
    cout << "Before swap\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swapnumber(a, b);

    cout << "\nAfter swap\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    return 0;
}

#include <iostream>
using namespace std;

int main() {

    int num1 = 5;

    int *ptr = &num1;

    cout << ptr << endl;

    cout << *ptr << endl;

    *ptr = 10;

    cout << ptr << endl;

    cout << *ptr << endl;

    cout << num1 << endl;




    return 0;
}

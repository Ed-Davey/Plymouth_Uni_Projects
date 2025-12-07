#include <iostream>
using namespace std;

int main() {

    int numbers [5] = {1, 3, 5, 7, 9};

    int *nPtr;

    nPtr = numbers;

    for (int i = 0; i < 5; i++) {
        cout << *nPtr << endl;
        nPtr++;
    }

    nPtr = numbers;

    for (int i = 0; i < 5; i++) {
        *nPtr +=2;
        nPtr++;
    }

    nPtr = numbers;

    for (int i = 0; i < 5; i++) {
        cout << *nPtr << endl;
        nPtr++;
    }

    return 0;
}

#include <iostream>
using namespace std;
#include <string>

int main() {

    char *WordArray = new char[20];


    cout << "Enter a word: ";
    cin.getline(WordArray, 20);

    cout << endl << "You entered: " << WordArray << endl;
    cout << "length: " << strlen(WordArray) << endl;

    delete[] WordArray;

    return 0;
}

#include <iostream>
using namespace std;

int main() {

    int choice;

    cout << "1: Start game\n2: Load game\n3: Quit\n" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Start game" << endl;
            break;

        case 2:
            cout << "Load game" << endl;
            break;

        case 3:
            cout << "Quit" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
    }




    return 0;
}

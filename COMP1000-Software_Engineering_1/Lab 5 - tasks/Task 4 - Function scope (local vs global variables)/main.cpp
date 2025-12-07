#include <iostream>
#include <cstdlib>
using namespace std;

int counter = 0;

void incrementCounter(int &counter) {
    counter++;
}

void decrementCounter(int &counter) {
    counter--;
}

int main() {

    srand((unsigned)time(NULL));

    for (int i = 1; i <= 10; i++) {
        int random = rand() % 2;

        if (random == 0) {
            incrementCounter(counter);
        }
        else if (random == 1) {
            decrementCounter(counter);
        }
        else {
            cout << "ERROR!" << endl;
        }

        cout << counter << endl;
    }




    return 0;
}

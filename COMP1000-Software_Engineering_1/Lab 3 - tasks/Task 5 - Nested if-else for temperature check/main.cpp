#include <iostream>
using namespace std;

int main() {

    int temp;

    cout << "What is the temperature in °C? ";
    cin >> temp;

    if (temp < 0) {
        cout << "It's freezing.";
    } else if (temp >= 0 && temp <= 15) {
        cout << "It's cold.";
    } else if (temp > 15 && temp <= 30) {
        cout << "It's warm.";
    } else if (temp > 30) {
        cout << "It's hot.";
    } else {
        cout << "invalid temperature";
    }





    return 0;
}

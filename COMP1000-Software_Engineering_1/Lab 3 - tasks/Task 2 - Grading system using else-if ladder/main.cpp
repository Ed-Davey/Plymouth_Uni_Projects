#include <iostream>
using namespace std;

int main() {

    int grade;

    cout << "Please enter your grade: ";
    cin >> grade;

    if (grade >= 90 && grade <= 100) {
        cout << "Grade A";
    } else if (grade >= 80 && grade < 90) {
        cout << "Grade B";
    } else if (grade >= 70 && grade < 80) {
        cout << "Grade C";
    } else if (grade >= 60 && grade < 70) {
        cout << "Grade D";
    } else if (grade >= 0 && grade < 60) {
        cout << "Grade F";
    } else {
        cout << "ERROR! Grade out of range!";
    }

    return 0;
}

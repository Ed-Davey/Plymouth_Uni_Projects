#include <iostream>
using namespace std;
#include <string>

int main() {
    //initial values
    string name = "Alice";
    int age = 20;
    float height = 1.65;
    char grade = 'B';

    //output initial values
    cout << "Name: " << name << ", Age: " << age << ", Height: " << height << ", Grade: " << grade << endl;

    //updated value
    name = "Bob";
    age = 22;
    height = 1.75;
    grade = 'A';

    //output updated values
    cout << "Name: " << name << ", Age: " << age << ", Height: " << height << ", Grade: " << grade << endl;

    return 0;
}

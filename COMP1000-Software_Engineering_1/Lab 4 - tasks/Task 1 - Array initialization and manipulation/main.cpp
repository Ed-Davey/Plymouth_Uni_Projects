#include <iostream>
using namespace std;
int main()
{

    int numbers[10];
    int total = 0;
    float average = 0;
    int NumOFElements = 0;

    for (int i = 0; i < 10; i++) {
        numbers[i] = (i + 1);
        NumOFElements++;
        cout << numbers[i] << endl;
    }

    for (int i = 0; i < 10; i++) {
        total = total + numbers[i];
    }

    cout << "The total is " << total << endl;

    average = float(total) / float(NumOFElements);

    cout << "The average is " << average << endl;

    return 0;
}

#include <iostream>
using namespace std;

void trackFunctionCalls() {

    static int timesCalled = 1;

    cout << "This function has been called " <<timesCalled << " times.\n" << endl;

    timesCalled ++;

}

int main() {

    for (int i = 1; i <= 10; i++) {
        trackFunctionCalls();
    }




    return 0;
}

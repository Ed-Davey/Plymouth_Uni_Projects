#include <iostream>
using namespace std;

float distancex;
float distancey;

float calculateDistance(float x1, float y1, float x2, float y2, float &distancex, float &distancey) {


    distancex = x2-x1; distancey = y2-y1;

    return distancex + distancey;

}

int main() {

    float x1, y1, x2, y2;

    cout << "Please enter the first coordinate of x and y" << endl;
    cin >> x1 >> y1;

    cout << "Please enter the first coordinate of x and y" << endl;
    cin >> x2 >> y2;

    calculateDistance(x1, y1, x2, y2, distancex, distancey);

    cout << "The different between the two points is: " << distancex << ", " << distancey << endl;



    return 0;
}

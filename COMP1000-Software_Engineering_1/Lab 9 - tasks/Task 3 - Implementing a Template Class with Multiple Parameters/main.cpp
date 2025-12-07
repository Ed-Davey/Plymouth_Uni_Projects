#include <iostream>
#include "main.h"
#include <string>

int main() {

    pair<int,float>pair1(10,20.5);
    pair<std::string, char>pair2("Hello", 'A');

    std::cout << "First = " << pair1.displayFirst() << ", Second = " << pair1.displaySecond() << std::endl;
    std::cout << "First = " << pair2.displayFirst() << ", Second = " << pair2.displaySecond() << std::endl;


    return 0;
}

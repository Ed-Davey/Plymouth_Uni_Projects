#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream inputFile("data.txt");
    std::string name;
    int age;
    if (inputFile.is_open()) {
        while (inputFile >> name >> age) {
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Error opening file." << std::endl;
    }
    return 0;
}
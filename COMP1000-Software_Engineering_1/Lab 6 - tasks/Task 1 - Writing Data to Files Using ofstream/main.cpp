#include <iostream>
#include <fstream>
#include <iomanip>
int main() {
    std::ofstream outputFile("data.txt");
    if (outputFile.is_open()) {
        outputFile << std::setw(10) << "Name" << std::setw(5) << "Age" << std::endl;
        outputFile << std::setw(10) << "Alice" << std::setw(5) << 30 << std::endl;
        outputFile << std::setw(10) << "Bob" << std::setw(5) << 25 << std::endl;
        outputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    return 0;
}
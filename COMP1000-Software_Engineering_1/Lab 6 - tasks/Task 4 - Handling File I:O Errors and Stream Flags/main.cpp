#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::ifstream inputFile("test.txt");
    std::string line;
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }
    while (getline(inputFile, line)) {
        if (inputFile.fail()) {
            std::cerr << "Read error occurred." << std::endl;
            inputFile.clear(); // Clear error state
            continue;
        }
        std::cout << line << std::endl;
    }
    if (inputFile.eof()) {
        std::cout << "Reached end of file." << std::endl;
    } else {
        std::cerr << "An unknown error occurred." << std::endl;
    }
    inputFile.close();
    return 0;
}
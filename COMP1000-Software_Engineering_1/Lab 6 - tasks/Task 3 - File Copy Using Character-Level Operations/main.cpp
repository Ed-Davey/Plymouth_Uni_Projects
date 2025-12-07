#include <iostream>
#include <fstream>
int main() {
    std::ifstream inputFile("source.txt");
    std::ofstream outputFile("destination.txt");
    char ch;
    if (inputFile.is_open() && outputFile.is_open()) {
        while (inputFile.get(ch)) {
            outputFile.put(ch);
        }
        inputFile.close();
        outputFile.close();
    } else {
        std::cout << "Error opening files." << std::endl;
    }
    return 0;
}
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main() {
    std::ifstream logFile("application.log");
    std::string line;
    int errorCount = 0, warningCount = 0;

    if (logFile.is_open()) {
        while (std::getline(logFile, line)) {
            if (line.find("ERROR") != std::string::npos) {
                std::cout << line << std::endl;
                errorCount++;
            }
            if (line.find("WARNING") != std::string::npos) {
                std::cout << line << std::endl;
                warningCount++;
            }
        }
        logFile.close();
        std::cout << "Total ERRORS: " << errorCount << std::endl;
        std::cout << "Total WARNINGS: " << warningCount << std::endl;
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    return 0;
}

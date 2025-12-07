#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("data.json");
    std::string line;
    bool inArray = false;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            // Remove whitespace from the beginning of the line
            line.erase(0, line.find_first_not_of(" \t\n\r"));

            // Check for start of JSON array
            if (line == "[") {
                inArray = true;
                continue;
            }

            // Check for end of JSON array
            if (line == "]") {
                inArray = false;
                continue;
            }

            if (inArray) {
                std::string name, grades, grade;

                // Check for "name" line
                if (line.find("\"name\"") != std::string::npos) {
                    auto startPos = line.find(":") + 3;  // Move to the start of the name value
                    auto endPos = line.rfind('"');       // Find the ending quote
                    name = line.substr(startPos, endPos - startPos);
                    std::cout << "Name: " << name << ", Grades: ";
                }

                // Check for "grades" line and parse the grades array
                if (line.find("\"grades\"") != std::string::npos) {
                    auto startPos = line.find("[") + 1;
                    auto endPos = line.find("]");
                    grades = line.substr(startPos, endPos - startPos);
                    std::istringstream gradesStream(grades);

                    // Read individual grades
                    bool first = true;
                    while (getline(gradesStream, grade, ',')) {
                        if (!first) {
                            std::cout << ", ";
                        }
                        std::cout << grade;
                        first = false;
                    }
                    std::cout << std::endl;
                }
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

    return 0;
}

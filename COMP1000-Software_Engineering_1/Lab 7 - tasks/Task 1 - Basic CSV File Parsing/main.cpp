#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::ifstream file("data.csv");
    std::string line;

    if (file.is_open()) {
        const int nameWidth = 9;
        const int ageWidth = 4;
        const int cityWidth = 10;

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string name, age, city;
            getline(ss, name, ',');
            getline(ss, age, ',');
            getline(ss, city, ',');
            std::cout << "Name: " << std::setw(nameWidth) << std::left << name
                      << "Age: " << std::setw(ageWidth) << std::left << age
                      << "City: " << std::setw(cityWidth) << std::left << city << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    return 0;
}

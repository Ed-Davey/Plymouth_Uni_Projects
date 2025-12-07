#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    int year;

public:
    Car() : make("unknown"), year(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    Car(std::string m, int y) : make(m), year(y) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    ~Car() {
        std::cout << "Destructor called for " << make << ", year: " << year << std::endl;
    }

    void display() {
        std::cout << "Car make: " << make << " , year: " << year << std::endl;
    }
};

int main()
{
    Car car1;
    car1.display();

    Car car2("Toyota", 2021);
    car2.display();

    return 0;
}

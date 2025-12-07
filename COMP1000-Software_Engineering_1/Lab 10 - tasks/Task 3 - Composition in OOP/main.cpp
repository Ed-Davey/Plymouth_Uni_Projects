#include <iostream>
#include <string>

//composed  class
class Address {
private:
    std::string street, city, postcode;
public:
    Address(std::string st, std::string c, std::string pc) : street(st), city(c), postcode(pc) {};
    void displayAddress() {
        std::cout << "Address: " << street << ", " << city << ", " << postcode << std::endl;
    }
};

//main class
class Person {
private:
    std::string name;
    int age;
    Address address;
public:
    Person(std::string n, int a, Address addr) : name(n), age(a), address(addr) {};

    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        address.displayAddress();
    }
};

int main()
{
    Address addr("Egloshayle road", "Wadebridge", "PL27 6HW");
    Person person("Edward Davey", 19, addr);
    person.displayInfo();
    return 0;
}

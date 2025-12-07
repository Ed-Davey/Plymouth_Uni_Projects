#include <iostream>
#include <string>

//base class
class vehicle {
protected:
    std::string make;
    std::string model;
public:
    vehicle(std::string mk, std::string mdl) : make(mk), model(mdl) {}

    virtual void displayInfo() {
        std::cout << "Make: " << make << ", Model: " << model;
    }
};

//derived class 1
class car : public vehicle {
private:
    int NumberOfDoors;
public:
    car(std::string mk, std::string mdl, int door) : vehicle(mk, mdl), NumberOfDoors(door) {}

    void displayInfo() override {
        vehicle::displayInfo();
        std::cout << ", Number of Doors: " << NumberOfDoors << std::endl;
    }
};

//derived class 2
class bike : public vehicle {
private:
    bool HasCarrier;
public:
    bike(std::string mk, std::string mdl, bool carrier) : vehicle(mk, mdl), HasCarrier(carrier) {}

    void displayInfo() override {
        vehicle::displayInfo();
        std::cout << ", Has Carrier: " << (HasCarrier ? "Yes" : "No") << std::endl;
    }
};

int main()
{
    car Car("Ford", "Mustang", 5);
    bike Bike("Yamaha", "MT-15", true);

    Car.displayInfo();
    Bike.displayInfo();

    return 0;
}

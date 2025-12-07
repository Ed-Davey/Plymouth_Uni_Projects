#include <iostream>

//Base class
class animal {
public:
    virtual void speak() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

//derived class
class dog : public animal {
public:
    void speak() override{
        std::cout << "Dog barks" << std::endl;
    }
};

//derived class
class cat : public animal {
public:
    void speak() override{
        std::cout << "Cat meows" << std::endl;
    }
};

int main()
{
    animal *a = new dog();
    a->speak();
    delete a;

    animal *b = new cat();
    b->speak();
    delete b;

    animal rabbit;
    rabbit.speak();

    return 0;
}

#include <iostream>

class Counter {
private:
    static int count;

public:
    Counter() {count++;}
    ~Counter() {count--;}

    static int getCount() {return count;}
};

int Counter::count = 0;

int main()
{
    Counter c1;
    std::cout << "Current Count: " << Counter::getCount() << std::endl;

    Counter c2;
    std::cout << "Current Count: " << Counter::getCount() << std::endl;

    {
        Counter c3;
        std::cout << "Current Count: " << Counter::getCount() << std::endl;
    }

    std::cout << "Current Count: " << Counter::getCount() << std::endl;

    return 0;
}

#include <iostream>
#include <string>

class Book {
    private:
        std::string title;
        std::string author;
        float price;

    public:
    Book(std::string t, std::string a, float p) : title(t), author(a), price(p) {}
        void displayInfo() {
            std::cout << "Title: " << title << ", Author: " << author << ", Price: " << price << std::endl;
        }

};

int main()
{
    Book book("The C++ Programming Language", "Bjarne Stroustrup", 39.99);
    book.displayInfo();

    return 0;
}

#include "printer.h"
#include <iostream>
#include <algorithm>

// Overloaded method for int
void Printer::print(int value) {
    std::cout << "Double of " << value << ": " << value * 2 << std::endl;
}

// Overloaded method for std::string (passed as const reference)
void Printer::print(const std::string& value) {
    std::string uppercased = value;
    std::transform(uppercased.begin(), uppercased.end(), uppercased.begin(), ::toupper);
    std::cout << "Uppercase of \"" << value << "\": " << uppercased << std::endl;
}

// Overloaded method for const char[] (C-string literals)
void Printer::print(const char* value) {
    std::string str(value);  // Convert C-string to std::string
    print(str);  // Call the std::string version
}

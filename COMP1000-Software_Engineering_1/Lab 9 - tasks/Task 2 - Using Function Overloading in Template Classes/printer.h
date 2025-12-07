#ifndef PRINTER_H
#define PRINTER_H

#include <string>

class Printer {
public:
    // Overloaded method for int
    void print(int value);

    // Overloaded method for std::string (passed as const reference)
    void print(const std::string& value);

    // Overloaded method for const char[] (C-string literals)
    void print(const char* value);
};

#endif // PRINTER_H

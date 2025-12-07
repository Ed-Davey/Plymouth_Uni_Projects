#include "printer.h"

int main() {
    Printer printer;

    printer.print(5);            // Calls the int overload
    printer.print("hello");      // Calls the const char* overload, which converts to std::string

    return 0;
}

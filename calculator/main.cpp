// .cpp contain the main source code
// clang++ calculator/calculator.cpp calculator/main.cpp -o bin/calculator 
// to compile, you need both files
#include <iostream>
#include "calculator.h"

int main() {
    greeter();

    int choice;
    std::cin >> choice;

    int a, b, c;

    if (choice == 1) {
        get_two_numbers(a, b);
        c = a + b;
        std::cout << "Result: " << c << std::endl;
    }
    else if (choice == 2) {
        get_two_numbers(a, b);
        c = a - b;
        std::cout << "Result: " << c << std::endl;
    }
    else if (choice == 3) {
        get_two_numbers(a, b);
        c = a * b;
        std::cout << "Result: " << c << std::endl;
    }
    else if (choice == 4) {
        get_two_numbers(a, b);
        if (b == 0) {
            print_line("Error: Cannot divide by zero.");
        } else {
            c = a / b;
            std::cout << "Result: " << c << std::endl;
        }
    }
    else {
        print_line("Invalid choice.");
    }

    return 0;
}

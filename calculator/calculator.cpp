#include "calculator.h"

#include <iostream>

void print_line(const std::string &msg) {
    std::cout << msg << std::endl;
}

void greeter() {
    print_line("Hello! I am a calculator.");
    print_line("Choose an operation:");
    print_line("1) Add");
    print_line("2) Subtract");
    print_line("3) Multiply");
    print_line("4) Divide");
}

void get_two_numbers(int &a, int &b) {
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
}

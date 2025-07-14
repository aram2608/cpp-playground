#include <iostream>
#include "circle_calc.h"

void print_line(const std::string& msg) {
    std::cout << msg << std::endl;
}

void greeter() {
    print_line("Hello! I am a circle calculator.");
    print_line("Choose an option.");
    print_line("1) Circumference.");
    print_line("2) Area.");
}

void get_number(double &a) {
    std::cout << "Enter the radius of the circle: ";
    std::cin >> a;
}

double area(double a) {
    const double pi = 3.14;
    return pi * a * a;
}

double circ(double a) {
    const double pi = 3.14;
    return pi * a * 2;
}

#include <iostream>

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

void area(double &a) {
    const double pi = 3.14;
    double a = pi * a * a;
}

void circ(double &a) {
    const double pi = 3.14;
    double a = pi * a * 2;
}#ifndef CIRCLE_CALC_H
#define CIRCLE_CALC_H

#include <string>

void print_line(const std::string& msg);
void greeter();
void get_number(double &a);
double area(double &a);
double circ(double &a);

#endif#include <iostream>
#include "circle_calc.h"

int main() {
    // constants are read only, they can not be modified
    greeter();

    double a;

    int choice;
    std::cin >> choice;

    if ( choice == 1) {
        get_number(a);
        circ(a);
        std::cout << "Result: " << a << std::endl;
    }
    else if ( choice == 2 ) {
        get_number(a);
        area(a);
        std::cout << "Result: " << a << std::endl;
    }
    return 0;
}
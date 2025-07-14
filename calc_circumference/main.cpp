#include <iostream>
#include "circle_calc.h"

int main() {
    greeter();

    double a;
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        get_number(a);
        double result = circ(a);
        std::cout << "Circumference Result: " << result << std::endl;
    }
    else if (choice == 2) {
        get_number(a);
        double result = area(a);
        std::cout << "Area Result: " << result << std::endl;
    }
    else {
        print_line("Invalid choice.");
    }

    return 0;
}

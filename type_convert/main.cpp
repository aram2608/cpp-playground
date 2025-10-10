#include <iostream>

int main() {
    /*
    Type conversion can be implicit or explicit
    */

    // Implicit conversion
    int x = 3.14;

    double y = (int) 2.5;

    std::cout << x << "\n" << y << std::endl;
    std::cout << "Watch me switch 100 to a char!\n"
              << 100 << "\n"
              << char(100) << "\nASCII YEAH!" << std::endl;

    return 0;
}
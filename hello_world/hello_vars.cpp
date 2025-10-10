#include <iostream>

int main() {
    int x; // variable declaration
    int y;

    x     = 5; // variable assignment
    y     = 6;
    int z = x + y;

    // double is a number plus a decimal
    double a = 2.5;

    // char is a single character
    char grade = 'A';

    // Boolean (true or false)
    bool student = true;

    // Float
    float e = 2.45;

    // strings are multiple characters
    std::string name = "Jerry";

    // A string literal is printed lines of string
    // They are not stored anywhere just printed straight up
    std::cout << "Cool math: " << z << std::endl;
    std::cout << "Double: " << a << std::endl;
    std::cout << "Your grade is an: " << grade << std::endl;
    std::cout << "Your name is: " << name << std::endl;
    std::cout << "This is a float: " << e << std::endl;
    return 0;
}
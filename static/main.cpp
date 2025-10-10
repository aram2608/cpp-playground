#include <iostream>

/*
 * When static is used inside of a function, the variable is initilaized once and is
 * remembered for future calls to the function
 */

void my_function() {
    // Initialized once
    static int counter = 0;
    std::cout << counter << std::endl;
    counter++;
}

// When used with global variables, it restricts the variable to the translation
// unit, meaning if this was a multifile project, no other file could use this variable

static const int WINDOW_SIZE = 1000; // is locked to this file

// For static member variables, the class owns it rather than any particular instance
// it has to be defined outside of the class declaration

// Similarly, member methods are owned by the class but they can only access static
// variables and methods since they dont have a *this pointer

class MyClass {
  public:
    static int  count;
    static void print_count() {
        std::cout << count << std::endl;
    }
};
// Definition and initialization
int MyClass::count = 0;

int main() {
    my_function(); // prints 0
    my_function(); // prints 1

    MyClass::print_count();
    return 0;
}
#include <iostream>

using std::cout;
using std::endl;

int main() {

    int students = 20;

    // Add and assign similar to python
    students += 1;

    cout << students << endl;

    // Increment operator
    students ++;

    cout << students << endl;

    // Subtraction, same pattern as addition
    students -= 1;
    // Decrement operation
    students --;

    cout << students << endl;

    // Multiplication
    students *= 2;

    cout << students << endl;

    // Division, the decimal portion is lost
    students /= 3;

    cout << students << endl;

    // Modulo op same as Python
    int num = 6;
    int rem = num % 2;
    if ( rem == 0 ) {
    cout << "Even" << endl;
    }
    else {
    cout << "Odd" << endl;
    }
    return 0;
}
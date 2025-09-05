#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printer(int og, int num2) {
    if (og == 1) {
        cout << "The " << og << "st number of the fibonacci sequence is: " << num2 << endl;
    } else if (og == 2) {
        cout << "The " << og << "nd number of the fibonacci sequence is: " << num2 << endl;
    } else if (og == 3) {
        cout << "The " << og << "rd number of the fibonacci sequence is: " << num2 << endl;
    } else {
        cout << "The " << og << "th number of the fibonacci sequence is: " << num2 << endl;
    }
}

void fib(int range) {
    int og = range;
    // Any number bigger than this overflows
    if (range >= 95) {
        cout << "Overflow, exiting..." << endl;
        return;
    }

    long long num1 = 0;
    long long num2 = 1;
    while (range > 1) {
        range--;
        long long num3 = num2;
        num2           = num1 + num2;
        num1           = num3;
    }
    printer(og, num2);
}

int main() {
    int a;
    cin >> a;
    fib(a);
    return 0;
}
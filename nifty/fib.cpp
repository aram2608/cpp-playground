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

void fib(int n) {
    // Any number bigger than this overflows
    if (n >= 95) {
        cout << "Overflow, exiting..." << endl;
        return;
    } else if (n <= 1) {
        printer(n, n);
        return;
    }

    int prev2 = 1, prev1 = 0;
    int curr;

    for (int i = 2; i <= n; i++) {
        curr  = prev2 + prev1;
        prev1 = prev2;
        prev2 = curr;
    }
    printer(n, curr);
}

int main() {
    int a;
    cin >> a;
    fib(a);
    return 0;
}
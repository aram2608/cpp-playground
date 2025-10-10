#include <iostream>

int main() {
    int a = 10;
    int b = 5;
    // max_val will be 10
    // condition ? if_true : if_false
    int max_val = (a > b) ? a : b;
    std::cout << max_val << std::endl;
    return 0;
}
#include <iostream>

int main() {
    int a = 10;
    int b = 5;
    int max_val;

    // Using the conditional operator to find the maximum value
    // Lets you write single line if statements
    max_val = (a > b) ? a : b; 

    std::cout << "The maximum value is: " << max_val << std::endl; // Output: 10

    return 0;
}
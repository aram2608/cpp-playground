#include <ctime>
#include <iostream>
#include <random>

int main() {
    // Mersenne twister algorithm
    // Initializing it with the current time ensures that the numbers are always
    // hard to predict
    std::random_device rd;
    std::mt19937       rng(std::time(nullptr));
    // A better and higher quality way is to use a random_device
    std::mt19937 rng2(rd());

    // We print the random number
    std::cout << rng() << std::endl;
    std::cout << rng2() << std::endl;

    return 0;
}
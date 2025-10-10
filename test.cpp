#include <algorithm>
#include <array>
#include <iostream>
#include <memory>

int main() {
    // Loops always check the condition before running, however the increment always happens
    // after the first loop
    for (int i = 0; i <= 10; ++i) {
        // 0 is printed first, if the incrment occured during the first pass it would have
        // printed 1 instead.
        std::cout << i << std::endl;
    }
    // This wont run as the check never passes
    for (int i = 11; i <= 10; ++i) {
        std::cout << "New loop" << std::endl;
        std::cout << i << std::endl;
    }

    // We create a new pointer to an int
    int *ptr = new int;
    // We can then assign it a value
    *ptr = 10;

    // We can see the memory location
    std::cout << "Memory location: " << ptr << std::endl;
    // We can derefernce to see the value
    std::cout << "Value: " << *ptr << std::endl;

    // Must always use delete with pointers created by new
    delete ptr;

    // Smart pointers are even better since they deallocate themselves
    std::unique_ptr<int> smrt_ptr = std::make_unique<int>(5);

    std::cout << "Memory location: " << smrt_ptr << std::endl;
    std::cout << "Value: " << *smrt_ptr << std::endl;

    // We create an array of 5 ints
    std::array<int, 5> arr;
    int                value = 0;
    // Iota at\uto files when provided with a function, in this case a lambda
    std::generate(arr.begin(), arr.end(), [&]() { return value++; });

    // We can return the address of an object using the address of operator &
    for (auto &val : arr) {
        std::cout << "I am the array value at: " << &val << " Value: " << val << std::endl;
    }
    return 0;
}
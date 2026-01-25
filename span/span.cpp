#include <iostream>
#include <vector>
#include <span>

void print_elements(std::span<const int> s) {
    for (int element : s) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    int my_array[] = {6, 7, 8};

    // Create a span from a std::vector
    print_elements(my_vector);

    // Create a span from a C-style array
    print_elements(my_array);

    // Create a sub-span (view of a portion of the data)
    print_elements(std::span(my_vector.data() + 1, 3)); // View elements 2, 3, 4

    return 0;
}
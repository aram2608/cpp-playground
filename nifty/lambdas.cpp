#include <iostream>
#include <memory>

class MyClass {
  public:
    int member_var = 5;
    // In a class, we can use [this] to capture all member variables
    void do_something() {
        auto lambda_this = [this]() { std::cout << "Member var: " << member_var << std::endl; };
        lambda_this();
    }
};

int main() {
    int x = 10;
    // The [] allows the capture of variable in the surrounding scope
    // Here we capture a copy of x
    // We can also use [=] and capture the (args) by value as well
    auto lambda_val = [x]() {
        // x inside the lambda is a copy, its value remains 10
        std::cout << "Value capture: " << x << std::endl;
    };
    // Modifying x after lambda creation
    x = 20;
    // Output: Value capture: 10
    lambda_val();

    int y = 10;
    // We can use [&] or [variable&] to capture a reference to variables as well
    auto lambda_ref = [&y]() {
        // y inside the lambda refers to the original y
        // Modifies the original y
        y++;
        std::cout << "Reference capture: " << y << std::endl;
    };
    // Output: Reference capture: 11
    lambda_ref();
    // Output: Original y after lambda: 11
    std::cout << "Original y after lambda: " << y << std::endl;

    // As of C++ 14 we can use [new_var = expression] to capture move only types
    // or perform complex initializations
    std::unique_ptr<int> ptr         = std::make_unique<int>(42);
    auto                 lambda_init = [my_ptr = std::move(ptr)]() {
        std::cout << "Captured unique_ptr value: " << *my_ptr << std::endl;
    };
    lambda_init();

    // Lambas with empty captures have the same signature as a function pointer
    // void (*functionptr)(object)

    // If a value is capture 

    return 0;
}
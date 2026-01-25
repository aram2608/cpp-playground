module;
#include <iostream>
export module MyModule;

export class MyClass {
public:
    MyClass() = default;
    void Hello() {
        std::cout << "Hello from MyClass in MyModule!" << std::endl;
    }
};

export void DoSomething() {
    std::cout << "Doing something!" << std::endl;
}
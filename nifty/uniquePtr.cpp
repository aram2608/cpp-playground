#include <iostream>
#include <memory>  // for std::unique_ptr

class MyObject {
public:
    MyObject() {
        std::cout << "Constructor called for MyObject\n";
    }
    ~MyObject() {
        std::cout << "Destructor called for MyObject\n";
    }
    void doSomething() {
        std::cout << "Doing something with MyObject...\n";
    }
};

class OtherObject {
public:
    OtherObject() {
        std::cout << "Constructor called for OtherObject\n";
    }
    ~OtherObject() {
        std::cout << "Destructor called for OtherObject\n";
    }
    void doSomething() {
        std::cout << "Doing something with OtherObject...\n";
    }
};

int main() {
    // Destructor is called automatically when obj goes out of scope
    std::unique_ptr<MyObject> obj = std::make_unique<MyObject>();
    obj->doSomething();

    OtherObject oobj = OtherObject();
    oobj.doSomething();

    return 0;
}
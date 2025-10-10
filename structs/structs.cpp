#include <iostream>

namespace HR {
    struct Employee {
        std::string name;
        int age;
    };

    struct AutoEmployee {
        AutoEmployee(std::string name, int age) : name(name), age(age) {};
        std::string name;
        int age;
    };

    struct PointerEmployee {
        PointerEmployee(std::string name, int age) : name(name), age(age) {
            std::cout << "Creating object and allocating memory." << std::endl;
            *ptr = 40;
        };
        ~PointerEmployee() {
            std::cout << "Destroying object and deallocating memeory." << std::endl;
            delete ptr;
        };
        std::string name;
        int age;
        int * ptr = new int;
    };
}

int main() {
    // Designated initializers
    HR::Employee me {
        .name = "Javier",
        .age = 24,
    };

    // Initalized using a defined constructor
    HR::AutoEmployee me_again = HR::AutoEmployee("Javier", 24);

    // Initalized using a defined constructor and destroyed using a destructor
    HR::PointerEmployee me_ptr = HR::PointerEmployee("Javier", 24);

    std::cout << "Employee: " << me.name << "\n";
    std::cout << "Age: " << me.age << std::endl;

    std::cout << "NEW" << std::endl;
    std::cout << "Employee: " << me_again.name << "\n";
    std::cout << "Age: " << me_again.age << std::endl;

    std::cout << "NEW" << std::endl;
    std::cout << "Employee: " << me_ptr.name << "\n";
    std::cout << "Age: " << me_ptr.age << std::endl;
    std::cout << "Ptr memory: " << me_ptr.ptr << " Value: " << *me_ptr.ptr << std::endl;
    return 0;
};
#include <iostream>
#include <string>

/*
>> extraction operators
<< insertion operators
*/

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string name;

    // << insertion operators
    cout << "What is your full name?" << endl;

    // std::getline() allows for white spaces
    std::getline(cin, name);

    cout << "Hello! " << name << endl;
    return 0;
}
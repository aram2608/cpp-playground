#include <iostream>
using std::cout;
using std::endl;

int main() {
    int a = 42;        // plain int
    int& r = a;        // reference (alias for a)
    int* p = &a;       // pointer to a

    cout << "a  = " << a << "   at address " << &a << endl;
    cout << "r  = " << r << "   at address " << &r << endl;
    cout << "p  = " << p << "   (pointer value = address of a)" << endl;
    cout << "*p = " << *p << "   (dereference p, gives value of a)" << endl;

    // change through reference
    r = 100;
    cout << "\nAfter r = 100;" << endl;
    cout << "a  = " << a << "   (changed through reference)" << endl;
    cout << "*p = " << *p << "   (same change seen through pointer)" << endl;

    // change through pointer
    *p = 7;
    cout << "\nAfter *p = 7;" << endl;
    cout << "a  = " << a << "   (changed through pointer)" << endl;
    cout << "r  = " << r << "   (reference also sees the change)" << endl;

    return 0;
}

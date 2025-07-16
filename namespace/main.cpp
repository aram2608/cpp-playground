#include <iostream>

/*
REMEMBER TO PREDECLARE YOUR FUNCTIONS, ALWAYS PUT THEM ABOVE MAIN OR THE FUNCTION THEY ARE
CALLED IN.
EITHER THAT OR INCLUDE A .h file.
*/

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
}

void printer(int &a) {
    // Saves from having to use repetive lines
    using std::cout;
    using std::endl;
    cout << a << endl;
}

void first_() {
    using namespace first;
    printer(x);
}

void second_() {
    using namespace second;
    printer(x);
}

int main() {
    /*
        A namespace provides a solution for preventing name conflicts
        in large projects. Each entity needs a unique name.
        A namespace allows for identically named entities as long as the namspaces
        are different
    using namespace std; can save on a bunch of typing but is not worth it due to naming
    conflicts
    */

    int x = 0;
    printer(x);
    first_();
    second_();
    return 0;
}
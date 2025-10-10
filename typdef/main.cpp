#include <iostream>
#include <vector>

// typedef std::vector<std::pair<std::string, int>> pairlist_t;

// Both of these create an alias for the type
typedef std::string str_t;
using num_t = int;

int main() {
    using std::cout;
    using std::endl;
    /*
    typedef lets you create an alias for another data type.
    A new identifier for an existing type.
    Helps with readibility and reduces typos

    Using keyword is often preferred since they work better with templates.
    */

    str_t first_name = "Javier";
    num_t age        = 24;

    cout << first_name << endl;
    cout << age << endl;
    return 0;
}
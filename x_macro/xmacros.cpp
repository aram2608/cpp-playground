#include <iostream>

#define COLOR_LIST                                                                                 \
    X(Red)                                                                                         \
    X(Green)                                                                                       \
    X(Blue)

#define X(name) name,
enum Color { COLOR_LIST };
#undef X

#define X(name) #name,
const char* ColorNames[] = {COLOR_LIST};
#undef X

int main() {
    for (auto color : ColorNames) {
        std::cout << color << "\n";
    }
    return 0;
}

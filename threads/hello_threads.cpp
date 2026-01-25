#include <thread>
#include <iostream>

void hello() {
    std::cout<< "Hello Concurrent World!" << std::endl;
}

int main() {

    std::thread t(hello);
    t.join();

    return 0;
}
#include <iostream>
#include <thread>

const long ITERATIONS = 100000;
long       counter    = 0;

void count() {
    for (long i = 0; i < ITERATIONS / 2; ++i) {
        counter = counter + 1;
    }
}

int main() {

    std::thread thread_1(count);
    std::thread thread_2(count);

    thread_1.join();
    thread_2.join();

    std::cout << counter << std::endl;

    return 0;
}
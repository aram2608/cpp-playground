#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

void console(uint64_t num) {
    char buf[21];
    size_t i = sizeof(buf);
    buf[--i] = '\n';
    do {
        buf[--i] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);

    write(STDOUT_FILENO, buf + i, sizeof(buf) - i);
}

int main() {

    console(10);
    console(20000000);
    console(2000000000000000000);
    console(0);

    return 0;
}
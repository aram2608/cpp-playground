#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>

// Signal handler function for Ctrl-C
void signal_handler1(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
    exit(signum);
}

int main() {

    // Store this programs PID
    pid_t process_id = getpid();
    std::cout << "Process ID: " << process_id << std::endl;

    // Install the SIGINT handler
    signal(SIGINT, signal_handler1);

    // "Listen" for incoming Ctrl-C signals
    while (true) {
        std::cout << "Program running..." << std::endl;
        sleep(1);
    }

    return 0;
}
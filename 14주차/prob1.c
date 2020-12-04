#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig) {
    write(STDOUT_FILENO, "Interrupt signal has been received\n", 35);
    exit(EXIT_SUCCESS);
}

int main() {
    char c;
    signal(SIGINT, (void *)sig_handler);
    while(read(STDIN_FILENO, &c, 1) != 0) {
        write(STDOUT_FILENO, &c, 1);
    }
    return 0;
}
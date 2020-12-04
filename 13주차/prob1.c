#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int sigint) {
    printf("Caught SIGINT\n");
    exit(EXIT_FAILURE);
}

int main() {
    char *name;
    signal(SIGINT, signal_handler);
    while(1) {
        name = malloc(sizeof(char)*20);
        printf("Enter: ");
        scanf("%s", name);
        printf("name: %s\n", name);
        free(name);
    }
}
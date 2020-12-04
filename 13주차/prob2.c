#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t Fork(void) {
    pid_t pid;
    if (pid = fork() < 0) {
        printf("Fork error\n");
        exit(0);
    }
    return pid;
}

int main() {
    int n, iter;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Enter the number of times to execute parent and child processes, respectively: ");
    scanf("%d", &iter); 
    pid_t pid = Fork();
    for (int i = 0; i < iter; i++) {
        if (pid == 0) {
            printf("child: %d\n", ++n);
        } else {
            printf("parent: %d\n", --n);
            wait(NULL);
        }
    }
    /* 
    if (pid == 0) {
        for(int i = 0; i < iter; i++) {
            printf("child: %d\n", ++n);
        }
    } else {
        for(int i = 0; i < iter; i++) {
            printf("parent: %d\n", --n);
        }
    } */
}
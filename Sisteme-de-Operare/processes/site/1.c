#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 1. Write a C program that creates n child processes. Each child process will print its PID 
// and its parent PID. The parent process will print its PID and the PID of each of the child processes.

int main() {
    int number_of_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &number_of_processes);

    for (int i = 0; i < number_of_processes; ++i) {
        int f = fork();

        if (f == 0) {
            printf("PID=%d, PPID=%d\n", getpid(), getppid());
            exit(0);
        }
    }

    for (int i = 0; i < number_of_processes; ++i) {
        wait(0);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 2. Write a C program that creates a linear hierarchy of n processes (a parent process 
// creates a child process, which in turn creates a child process, and so on).

void createProcesses(int num) {
    if (num == 0) {
        return;
    }

    printf("PID=%d, PPID=%d\n", getpid(), getppid());

    int f = fork();
    if (f == 0) {
        createProcesses(num - 1);    
        exit(0);
    }

    wait(0);
}

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    createProcesses(num_processes);

    return 0;
}

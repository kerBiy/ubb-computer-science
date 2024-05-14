#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// 3. Write a C program that creates a child process. Both the parent and the child processes will 
// run until they receive a SIGUSR1 signal. Implement signal handling such that if the parent receives 
// the SIGUSR1 signal first, it sends it to the child process as well. If the child process receives a 
// SIGUSR1 signal without the parent receiving the same signal, it will terminate and then the parent 
// should correctly call wait for the child process.

int f;

void childHandler(int sgn) {
    printf("Child process terminating...\n");
    exit(0);
}

void parentHandler(int sgn) {
    printf("Parent process terminating...\n");
    kill(f, SIGUSR1);
    wait(0);
    exit(0);
}

void zombieHandler(int sgn) {
    printf("Preventing zombie...\n");
    wait(0);
}

int main() {
    int f = fork();
    
    if (f == 0) {
        signal(SIGUSR1, childHandler);
        printf("PID=%d, PPID=%d", getpid(), getppid());
        while (1) {
            printf("Child working...");
            sleep(3);
        }
        exit(0);
    }

    signal(SIGUSR1, parentHandler);
    signal(SIGCHLD, zombieHandler);
    
    printf("PID=%d, PPID=%d", getpid(), getppid());
    while (1) {
        printf("Parent working...");
        sleep(2);
    }

    return 0;
}

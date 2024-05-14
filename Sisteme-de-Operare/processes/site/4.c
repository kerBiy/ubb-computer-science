#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 4. Write a C program that runs a bash command (potentially with arguments) received as a 
// command line argument and times its execution.

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Enter at least one arg");
        exit(1);
    }

    int f = fork();

    if (f == 0) {
        execvp(argv[1], argv + 1);
        perror("Error while running exec");
        exit(1);
    } else {
        wait(0);
    }
    return 0;
}

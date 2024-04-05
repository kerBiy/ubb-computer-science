#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    for(int i = 0; i < 3; ++i) {
        if(fork() == 0) {
            printf("Parent: %d; Child: %d\n", getppid(), getpid());
            for(int j = 0; j < 3; ++j) {
                if(fork() == 0) {
                    printf("Parent: %d; Child: %d\n", getppid(), getpid());
                    exit(0);
                }
            }
            for(int j = 0; j < 3; ++j) {
                wait(0);
            }
            exit(0);
        }
    }
    for(int i = 0; i < 3; ++i) {
        wait(0);
    }
    return 0;
}

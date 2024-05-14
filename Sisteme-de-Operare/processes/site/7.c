#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// 7. Write a C program that creates two child processes. The two child 
// processes will alternate sending random integers between 1 and 10 
// (inclusively) to one another until one of them sends the number 10. 
// Print messages as the numbers are sent.

int main() {
    int a2b[2], b2a[2];

    pipe(a2b);
    pipe(b2a);

    int f1 = fork();
    if (f1 == -1) {
        perror("Process A unable to start\n");
        exit(1);
    } else if (f1 == 0) { // A
        close(a2b[0]);
        close(b2a[1]);

        srandom(getpid());

        int n = 0;
        read(b2a[0], &n, sizeof(int));
        
        if (n != 10) {
            printf("A read %d from B\n", n);
        }

        while (n != 10) { 
            n = random() % 10 + 1;
            write(a2b[1], &n, sizeof(int));
            
            if (n == 10) {
                printf("Congrats! A hit 10\n");
                break;
            }

            read(b2a[0], &n, sizeof(int));
            
            if (n != 10) {
                printf("A read %d from B\n", n);
            }
        }

        close(a2b[1]);
        close(b2a[0]);

        exit(0);
    } 
    
    int f2 = fork();
    if (f2 == -1) {
        perror("Process B unable to start\n");
        exit(1);
    } else if (f2 == 0) { // B  
        close(a2b[1]);
        close(b2a[0]);

        srandom(getpid());

        int n = 0;
        while (n != 10) { 
            n = random() % 10 + 1;
            write(b2a[1], &n, sizeof(int));
            
            if (n == 10) {
                printf("Congrats! B hit 10\n");
                break;
            }

            read(a2b[0], &n, sizeof(int));
            
            if (n != 10) {
                printf("B read %d from A\n", n);
            }
        }

        close(a2b[0]);
        close(b2a[1]);

        exit(0);
    }
    
    wait(0);
    wait(0);

    return 0;
}

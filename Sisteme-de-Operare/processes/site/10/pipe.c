#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

// 10. Create two processes A and B. A generates a random number n between 50 and 200. 
// If it is even, it sends it to B, if it is odd it sends n+1 to B. B receives the number 
// and divides it by 2 and sends it back to A. The process repeats until n is smaller than 5. 
// The processes will print the value of n at each step.

int main() {
    int a2b[2], b2a[2];
    
    pipe(a2b);
    pipe(b2a);

    int f = fork();

    if (f == -1) {
        perror("Fork faild.\n");
        exit(1);
    } 

    if (f == 0) { // Program B
        close(a2b[1]);
        close(b2a[0]);

        while (1) {
            int number;
            read(a2b[0], &number, sizeof(int));

            if (number == -1) break;

            printf("B recives %d from A\n", number);
            number /= 2;

            printf("B sends %d to A\n", number);
            write(b2a[1], &number, sizeof(int));
        }

        close(a2b[0]);
        close(b2a[1]);
        exit(0);
    }

    // Program A
    close(a2b[0]);
    close(b2a[1]);
    
    srand(time(NULL));
    int number = rand() % 151 + 50;
    printf("A generated %d\n", number);

    while (number > 5) {
        if (number % 2 == 0) {
            number++;
        }

        write(a2b[1], &number, sizeof(int));
        printf("A sends %d to B\n", number);

        read(b2a[0], &number, sizeof(int));
        printf("A recives %d from B\n", number);
    }

    int stop = -1;
    write(a2b[1], &stop, sizeof(int));
   
    close(a2b[1]);
    close(b2a[0]);

    wait(0);

    return 0;
}

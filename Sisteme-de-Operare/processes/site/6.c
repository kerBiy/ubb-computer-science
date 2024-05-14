#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

// 6. Create a C program that generates N random integers (N given at 
// the command line). It then creates a child, sends the numbers via pipe. 
// The child calculates the average and sends the result back.

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("Invalid args\n");
        exit(1);
    }
    
    int p2c[2], c2p[2];
    
    pipe(p2c);
    pipe(c2p);

    int f = fork();

    if (f == -1) {
        perror("The fork has faild\n");
        exit(1);
    } else if (f == 0) {
        close(p2c[1]);
        close(c2p[0]);

        int n = 0;
        float res = 0;

        read(p2c[0], &n, sizeof(int));

        for (int i = 0; i < n; ++i) {
            int random_number;
            read(p2c[0], &random_number, sizeof(int));
            res += random_number;
        }

        res /= n;

        write(c2p[1], &res, sizeof(float));

        close(p2c[0]);
        close(c2p[1]);

        exit(0);
    } else {
        close(p2c[0]);
        close(c2p[1]);

        srandom(time(NULL));

        int n = atoi(argv[1]);
        float res = -1;

        write(p2c[1], &n, sizeof(int));
        
        for (int i = 0; i < n; ++i) {
            int random_number = random() % 100;
            printf("The %d random number is: %d\n", i, random_number);
            write(p2c[1], &random_number, sizeof(int));
        }

        wait(0);

        read(c2p[0], &res, sizeof(float));
        
        printf("The average is: %.2f\n", res);
        close(p2c[1]);
        close(c2p[0]);
    }
    
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// 2. Scrieti un program C care genereaza N numere intregi aleatoate (N dat la linia de comanda). 
// Apoi creeaza un proces fiu si ii trimite numerele prin pipe. Procesul fiu calculeaza 
// media numerelor si trimite rezultatul inapoi parintelui.

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("Args not valid.\n");
        return 1;
    }

    srand(time(NULL));

    int p2c[2], c2p[2];

    pipe(p2c);
    pipe(c2p);

    int f = fork();

    if (f == -1) {
        perror("The fork faild.\n");
        return 1;
    }

    if (f == 0) {
        close(p2c[1]);
        close(c2p[0]);

        float average = 0;
        int n;

        read(p2c[0], &n, sizeof(int));

        for(int i = 0; i < n; ++i) {
            int number;
            read(p2c[0], &number, sizeof(int));
            printf("Child recives %d from Parent\n", number);

            average += number;
        }

        average /= n;
        write(c2p[1], &average, sizeof(float));

        close(p2c[0]);
        close(c2p[1]);
        exit(0);
    }
    
    close(p2c[0]);
    close(c2p[1]);

    int n = atoi(argv[1]);
    write(p2c[1], &n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        int random_number = rand() % 10 + 1;

        printf("Parent sents %d to Child\n", random_number);
        write(p2c[1], &random_number, sizeof(int));
    }

    float average;
    read(c2p[0], &average, sizeof(float));

    printf("The average of the numbers is %.2f\n", average);
    
    close(p2c[1]);
    close(c2p[0]);

    wait(NULL);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// 3. Scrieti un program C care creeaza doua procese fiu. Cele doua procese isi vor trimite alternativ 
// numere intregi intre 1 si 10 (inclusiv) pana cand unul din ele trimite numarul 10. 
// Afisati mesaje pe masura ce numerele sunt trimise.

int main() {
    int a2b[2], b2a[2];

    pipe(a2b);
    pipe(b2a);

    srand(time(NULL));

    int fA = fork();

    if (fA == -1) {
        perror("The fork for A faild.\n");
        exit(1);
    }

    if (fA == 0) {
        close(a2b[0]);
        close(b2a[1]);

        int random_number = 0;

        while (random_number != 10) {
            random_number = rand() % 10 + 1;

            write(a2b[1], &random_number, sizeof(int));
            printf("A sends %d to B\n", random_number);

            read(b2a[0], &random_number, sizeof(int));
            printf("A recives %d from B\n", random_number);
        }

        close(a2b[1]);
        close(b2a[0]);
        exit(0);
    }

    int fB = fork();
    
    if (fB == -1) {
        perror("The fork for B faild.\n");
        exit(1);
    }

    if (fB == 0) {
        close(a2b[1]);
        close(b2a[0]);

        int random_number = 0;

        while (random_number != 10) {
            read(a2b[0], &random_number, sizeof(int));
            printf("B recives %d from A\n", random_number);

            random_number = rand() % 10 + 1;

            write(b2a[1], &random_number, sizeof(int));
            printf("B sents %d to A\n", random_number);
        }

        close(a2b[0]);
        close(b2a[1]);
        exit(0);
    }

    close(a2b[0]);
    close(a2b[1]);
    close(b2a[0]);
    close(b2a[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}

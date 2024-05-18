#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

// 1. Procesul A citeste N intregi de la tastatura si ii trimite unui proces numit B. 
// Procesul B va adauga un numar aleator, intre 2 si 5, la toate numerele primite de la 
// procesul A si le va trimite unui alt proces numit C. Procesul C va adauga toate numerele 
// primite si va trimite suma inapoi procesului A. Toate procesele vor afisa un 
// mesaj cu numerele primite si trimise.


int main() {
    int a2b[2], b2c[2], c2a[2];

    pipe(a2b);
    pipe(b2c);
    pipe(c2a);

    srand(time(NULL));

    int fB = fork();

    if (fB == -1) {
        perror("Error fork b.\n");
        exit(1);
    }

    if (fB == 0) { // B
        close(a2b[1]);
        close(b2c[0]);
        close(c2a[0]);
        close(c2a[1]);

        int n;
        read(a2b[0], &n, sizeof(int));
        write(b2c[1], &n, sizeof(int));

        for (int i = 0; i < n; ++i) {
            int x;
            read(a2b[0], &x, sizeof(int));
            printf("B reads %d from A\n", x);

            int random = rand() % 4 + 2;
            x += random;

            printf("B sends %d to C\n", x);
            write(b2c[1], &x, sizeof(int));
        }

        close(a2b[0]);
        close(b2c[1]);
        exit(0);
    }

    int fC = fork();

    if (fC == -1) {
        perror("Error fork c.\n");
        exit(1);
    }

    if (fC == 0) { // C
        close(a2b[0]);
        close(a2b[1]);
        close(b2c[1]);
        close(c2a[0]);
   
        int sum = 0;
        int n;

        read(b2c[0], &n, sizeof(int));

        for (int i = 0; i < n; ++i) {
            int x;
            read(b2c[0], &x, sizeof(int));
            printf("C reads %d from B\n", x);

            sum += x;
        }

        write(c2a[1], &sum, sizeof(int));

        close(b2c[0]);
        close(c2a[1]);
        exit(0);
    }

    // A
    
    close(a2b[0]);
    close(b2c[0]);
    close(b2c[1]);
    close(c2a[1]);

    int n;
    scanf("%d", &n);
    write(a2b[1], &n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        write(a2b[1], &x, sizeof(int)); 
    }

    int res;
    read(c2a[0], &res, sizeof(int));

    printf("The sum is %d\n", res);

    wait(0);
    wait(0);
    
    close(a2b[1]);
    close(c2a[0]);

    return 0;
}

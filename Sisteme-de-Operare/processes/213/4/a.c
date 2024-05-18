#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

// 4. Scrieti 2 programe C care comunica prin fifo. Cele doua procese isi vor trimite alternant unul celuilalt 
// numere intre 1 si 10 (inclusiv) pana cand unul din ele trimite numarul 10. Afisati mesaje pe masura 
// ce se trimit numere. Unul dintre procese va fi responsabil pentru crearea si stergerea canalelor fifo.

int main() {
    mkfifo("a2bFifo", 0600);
    mkfifo("b2aFifo", 0600);

    int a2b = open("a2bFifo", O_WRONLY);
    int b2a = open("b2aFifo", O_RDONLY);

    srand(getpid());
    int random = 0;

    while (random != 10) {
        random = rand() % 10 + 1;

        write(a2b, &random, sizeof(int));
        printf("A wrote %d to B\n", random);

        read(b2a, &random, sizeof(int));
        printf("A read %d from B\n", random);
    }

    close(a2b);
    close(b2a);

    unlink("a2bFifo");
    unlink("b2aFifo");

    return 0;
}

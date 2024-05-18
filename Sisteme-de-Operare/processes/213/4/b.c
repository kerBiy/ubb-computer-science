#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int a2b = open("a2bFifo", O_RDONLY);
    int b2a = open("b2aFifo", O_WRONLY);

    srand(getpid());
    int random = 0;

    while (random != 10) {
        read(a2b, &random, sizeof(int));
        printf("B read %d from A\n", random);

        random = rand() % 10 + 1;

        write(b2a, &random, sizeof(int));
        printf("B write %d to A\n", random);
    }

    close(a2b);
    close(b2a);
    return 0;
}


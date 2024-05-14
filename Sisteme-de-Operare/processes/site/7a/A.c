#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main() {
    mkfifo("fifoA", 0600);
    printf("FIFO A was created\n");

    mkfifo("fifoB", 0600);
    printf("FIFO B was created\n");

    int fd_write = open("fifoA", O_WRONLY);
    int fd_read = open("fifoB", O_RDONLY);

    srand(getpid());

    while (1) {
        int number = rand() % 10 + 1;
        
        write(fd_write, &number, sizeof(int));
        printf("A sent %d\n", number);

        if (number == 10) break;

        read(fd_read, &number, sizeof(int));
        printf("A read %d\n", number);

        if (number == 10) break;
    }

    close(fd_write);
    close(fd_read);

    unlink("fifoA");
    printf("FIFO A deleted\n");

    unlink("fifoB");
    printf("FIFO B deleted\n");

    return 0;
}

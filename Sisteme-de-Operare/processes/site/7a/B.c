#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main() {
    int fd_read = open("fifoA", O_RDONLY);
    int fd_write = open("fifoB", O_WRONLY);

    srand(getpid());

    while (1) {
        int number;

        read(fd_read, &number, sizeof(int));
        printf("B read %d\n", number);

        if (number == 10) break;

        number = rand() % 10 + 1;
       
        write(fd_write, &number, sizeof(int));
        printf("B sent %d\n", number);
        
        if (number == 10) break;
    }

    close(fd_read);
    close(fd_write);

    return 0;
}

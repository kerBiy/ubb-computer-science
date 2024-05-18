#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1000

int main() {
    int fifo = open("myfifo", O_RDONLY);

    while (1) {
        int n;
        read(fifo, &n, sizeof(int));

        if (n < 0) break;

        char buf[SIZE + 1];
        read(fifo, buf, sizeof(char) * n);
        buf[n] = 0;

        printf("%s\n", buf);
    }
    
    printf("The a process was stoped.");
    close(fifo);
    return 0;
}

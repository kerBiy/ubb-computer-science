#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        perror("Args invalid.\n");
        exit(1);
    }

    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[2], O_WRONLY);

    int n;
    read(f1, &n, sizeof(int));

    char string[n];
    read(f1, string, sizeof(char) * n);
    printf("The program C has read the string %s from fifo1\n", string);

    write(f2, &n, sizeof(int));
    printf("The program C has writen the len %d to fifo2\n", n);

    close(f1);
    close(f2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        perror("Args are invalid");
        exit(1);
    }

    int f1 = open(argv[1], O_WRONLY);
    int f2 = open(argv[2], O_RDONLY);

    int len = strlen(argv[3]);
    write(f1, &len, sizeof(int));
    write(f1, argv[3], sizeof(char) * len);

    read(f2, &len, sizeof(int));
    printf("The size of the string from B is %d\n", len);

    close(f1);
    close(f2);

    return 0;
}

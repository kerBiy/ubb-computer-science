#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

// 8. Write 2 C programs, A and B. A receives however many command line 
// arguments and sends them to process B. Process B converts all lowercase 
// letters from the received arguments to uppercase arguments and sends 
// the results back to A. A reads the results, concatenates them and prints.

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("Args are invalid.");
        exit(0);
    }

    mkfifo("fifoA", 0600);
    mkfifo("fifoB", 0600);

    int a2b = open("fifoA", O_WRONLY);
    int b2a = open("fifoB", O_RDONLY);

    int total_size = 0;

    for (int i = 1; i < argc; ++i) {
        total_size += strlen(argv[i]) + 1; 
    }

    char res[total_size + 1];
    res[0] = 0;

    for (int i = 1; i < argc; ++i) {
        // Write the arg to b
        int len = strlen(argv[i]);
        write(a2b, &len, sizeof(int)); 
        write(a2b, argv[i], sizeof(char) * len);

        // read the res from b
        char tmp[len + 1];
        read(b2a, &len, sizeof(int));
        read(b2a, tmp, sizeof(char) * len); 
        tmp[len] = 0;

        strcat(res, tmp);
        strcat(res, " ");
    }

    int stop = -1;
    write(a2b, &stop, sizeof(int));

    res[total_size] = 0;
    printf("The res is: %s", res);

    close(a2b);
    close(b2a);

    unlink("fifoA");
    unlink("fifoB");

    return 0;
}

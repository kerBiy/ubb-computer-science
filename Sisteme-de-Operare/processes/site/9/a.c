#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 1000

// 9. Write two C programs that communicate via fifo. Program A is 
// responsible for creating/deleting the fifo. Program A reads commands 
// from the standard input, executes them and sends the output to program
// B. Program B keeps reading from the fifo and displays whatever it 
// receives at the standard output. This continues until program A 
// receives the "stop" command.

int main() {
    if (mkfifo("myfifo", 0600) < 0) {
        perror("Fifo error\n");
        exit(1);
    }

    printf("Fifo opened\n");
    int fifo = open("myfifo", O_WRONLY);
    
    char buf[SIZE + 1];
    char cmd[SIZE + 1];
    
    while(1) {
        int len = read(0, cmd, sizeof(char) * SIZE);  
        cmd[len] = 0;

        if (strncmp(cmd, "stop", 4) == 0) break;

        FILE* f = popen(cmd, "r");

        fread(buf, 1, SIZE, f); 
        int nr = strlen(buf);
        write(fifo, &nr, sizeof(int));
        write(fifo, buf, sizeof(char) * nr);
       
        pclose(f);
    }   

    int stop = -1;
    write(fifo, &stop, sizeof(int));

    close(fifo);
    unlink("myfifo");

    return 0;
}

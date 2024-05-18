#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// 5. Write a C program that implements the boltz game. Exactly N 
// processes (numbered 1 to N, where N is given) take turns incrementing 
// a number, starting from 1, and sending it to the next process. 
// Process 1 starts the game by incrementing the number and sends it 
// to process 2, which increments and sends it to process 3 and so on. 
// Process N will send the number back to process 1, ant the cycle starts 
// again. Each process must print the number it sends, unless the number 
// contains the digit 7 or is divisible by 7, in which case it must print 
// "boltz". Implement so that each process has a 1 in 3 chance to fail 
// printing "boltz" when it should, in which case the game stops.

int isBoltzNumber(int number) {
    if (number == 7 || number % 7 == 0) {
        return 1;
    }

    while (number) {
        if (number % 10 == 7) {
            return 1;
        }
        number /= 10;
    }

    return 0;
}

void boltz(int pipes[][2], int index, int n) {
    int number = 1;

    int read_index = index % n;
    int write_index = (index + 1) % n;

    for (int i = 0; i < n; ++i) {
        if (i != read_index) {
            close(pipes[i][0]);
        } 
        if (i != write_index) {
            close(pipes[i][1]);
        }
    }

    if (index == 0) {
        printf("The game has started!\n");
        write(pipes[write_index][1], &number, sizeof(int));
    }
    
    while (1) {
        read(pipes[read_index][0], &number, sizeof(int));

        if (number == 0) {
            write(pipes[write_index][1], &number, sizeof(int));
            break;
        }
        
        number++;

        if (isBoltzNumber(number)) {
            int success = rand() % 3;
            
            if (success) {
                printf("The player %d said Boltz!!!\n", index + 1);
            } else {
                printf("%d faild!\n", number);
                number = 0;
            }
        } else {
            printf("The player %d said %d\n", index + 1, number);
        }
        
        write(pipes[write_index][1], &number, sizeof(int));
    }
    wait(0);
    close(pipes[read_index][0]);
    close(pipes[write_index][1]);
}

int main() {
    int n = 10;
    int pipes[n][2];

    for (int i = 0; i < n; ++i) {
        if (pipe(pipes[i]) < 0) {
            perror("The pipe %d is bloked.\n");
            exit(1);
        }
    }

    srand(time(NULL));

    int i;
    for (i = 0; i < n; ++i) {
        int f = fork();

        if (f == -1) {
            perror("The fork has faild\n");
            exit(1);
        } else if (f != 0) {
            break;
        } 
    }
    
    if (i < n) {
        boltz(pipes, i, n);
    }

    return 0;
}

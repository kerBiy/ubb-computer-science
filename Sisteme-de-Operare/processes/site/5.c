#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

void boltz(int pipes[][2], int process, int nr) {
    
}

int main() {
    int pipes[10][2];
    int n = 10;

    for (int i = 0; i < n; ++i) {
        pipe(pipes[i]);
    }
    boltz(pipes, 0, n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// Scrieti un program in C care creaza un arbore de procese pe patru 
// nivele. Fiecare proces creaza cate un fiu, pana cand se ajunge 
// la 15 procese in total, inclusiv cu parintele.

//        __1__
//       /               \
//    _2_            _3_
//   /     \          /     \
//  4       5        6       7
// / \     / \      / \     / \
//8   9  10   11  12   13 14  15

// Fiecare proces afiseaza pe ecran "Sunt procesul #! Parintii mei sunt: 
// #!", apoi transmite parintelui global (adica procesului #1), prin 
// pipe, ID-ul propriu. Procesul #1 citeste toate ID-urile din pipe-urile 
// create si calculeaza suma lor. In final, parintele afiseaza suma. 
// Rezultatul ar trebui sa fie 120 (parintele aduna si ID-ul propriu)

// Spre exemplu, procesul 4 afiseaza:
//  Sunt procesul 4! Parintii mei sunt: 2,1!
//Spre exemplu, procesul 2 afiseaza:
//  Sunt procesul 2! Parintii mei sunt: 1!
//Spre exemplu, procesul 10 afiseaza:
//	Sunt procesul 10! Parintii mei sunt: 5,2,1!

void generateProcess(int level, int maxLevel, int parent, int pipe[2], int *currId) {
    if (level > maxLevel) return;

    for (int i = 0; i < 2; ++i) {
        int f = fork();

        if (f == -1) {
            perror("The fork faild\n");
            return;
        } else if (f == 0) {
            close(pipe[0]);
            int id = *currId;
            (*currId)++;

            if (level == 1) {
                printf("I am %d. My parents are: 1\n", id);
            } else if (level == 2) {
                printf("I am %d. My parents are: %d 1\n", id, parent);
            } else {
                printf("I am %d. My parents are: %d %d 1\n", id, parent, parent / 2);
            } 
            generateProcess(level + 1, maxLevel, id, pipe, currId);

            write(pipe[1], &id, sizeof(int));
            close(pipe[1]);
            exit(0); 
        } else {
            wait(0);
        }

    }
}

int main() {
    int rootPipe[2];
    pipe(rootPipe);

    int currentId = 2;
    generateProcess(1, 3, 1, rootPipe, &currentId);

    close(rootPipe[1]);

    int sum = 1;
    for (int i = 0; i < 14; ++i) {
        int currPid;
        read(rootPipe[0], &currPid, sizeof(int));
        
        sum += currPid;
    }

    close(rootPipe[0]);
    printf("The sum of all pids is: %d\n", sum);
    
    return 0;
}

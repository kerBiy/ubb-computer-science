#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

//Sa se scrie un program A care primeste mai multe stringuri ca argumente in linia de comanda si fiecare dintre ele face urmatoarele:
//- creeaza in directorul curent doua FIFO-uri cu nume unice
//- ruleaza intr-un proces fiu programul B de mai jos cu argumentele necesare
//- ruleaza in alt proces fiu programul C de mai jos cu argumentele necesare

//Programul B:
//- primeste ca argumente doua nume de FIFO si un string
//- apoi scrie string-ul in primul FIFO
//- citeste lungimea stringului din al doilea FIFO
//- tiparestein consola lungimea stringului

// Programul C:
// - primeste ca argumente doua nume de FIFO
// - citeste un string din primul FIFO
// - scrie lungimea stringului in al doilea FIFO.

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("The args are invalid");
        exit(1);
    }

    for (int i = 1; i < argc; ++i) {
        printf("\nArg %d\n", i);

        char f1[32];
        char f2[32];

        sprintf(f1, "fifo1%d", i);
        sprintf(f2, "fifo2%d", i);

        mkfifo(f1, 0600);
        mkfifo(f2, 0600);

        printf("made fifo %s and %s\n", f1, f2);

        int fb = fork();

        if (fb == -1) {
            perror("Fork faild");
            exit(1);
        }

        if (fb == 0) { // B
            execl("./b", "./b", f1, f2, argv[i], NULL);
        }

        int fc = fork();

        if (fc == -1) {
            perror("Fork faild");
            exit(1);
        }

        if (fc == 0) { // C
            execl("./c", "./c", f1, f2, NULL);
        }

        wait(0);
        wait(0);

        unlink(f1);
        unlink(f2);
    }
    return 0;
}

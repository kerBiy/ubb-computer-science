// 15. Write a program that receives strings of characters as command line arguments. 
// For each string the program creates a thread which calculates the number of digits, the 
// number of leters and the number of special characters (anything other than a letter or digit). 
// The main program waits for the threads to terminate and prints the total results 
// (total number of digits, letters and special characters across all the received command 
// line arguments) and terminates. Use efficient synchronization. Do not use global variables

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    int digits;
    int letters;
    int specials;
} Data;

void *handler(void *a) {
    Data *res = (Data *) malloc(sizeof(Data));
    res->digits = 0;
    res->letters = 0;
    res->specials = 0;

    char *str = (char *)a;
    for (int i = 0, n = strlen(str); i < n; ++i) {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
            res->letters++;
        } else if ('0' <= str[i] && str[i] <= '9') {
            res->digits++;
        } else {
            res->specials++;
        }
    }

    free(str);
    return (void*) res;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "The args are invalid.\n");
        return 1;
    }

    pthread_t thread[argc];
    for (int i = 1; i < argc; ++i) {
        char *str = (char *) malloc(sizeof(char) * (strlen(argv[i]) + 1));
        strcpy(str, argv[i]);

        pthread_create(&thread[i], NULL, handler, (void*)str);
    }

    Data *res[argc];
    for (int i = 1; i < argc; ++i) {
        pthread_join(thread[i], (void**) &res[i]);
    }

    Data total = {0, 0, 0};
    for (int i = 1; i < argc; ++i) {
        total.digits += res[i]->digits;
        total.letters += res[i]->letters;
        total.specials += res[i]->specials;
        free(res[i]);
    }

    printf("The total freq is: digit=%d, letter=%d, special=%d\n", total.digits, total.letters, total.specials);

    return 0;
}


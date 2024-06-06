// Scrieti un program C care converteste toate literele mici din argumentele
// primite la linia de comanda in litere mari si afiseaza
// rezultatul.Folositi un thread pentru fiecare argument.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *handler(void *arg) {
    char *str = (char *)arg;

    for (int i = 0, n = strlen(str); i < n; ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] += 'A' - 'a';
        }
    }

    printf("The new string is: %s\n", str);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "The args are invalid...");
        return 1;
    }

    pthread_t t[argc - 1];

    for (int i = 1; i < argc; ++i) {
        char *string = (char *)malloc(strlen(argv[i]) * sizeof(char));
        strcpy(string, argv[i]);

        pthread_create(&t[i - 1], NULL, handler, (void *)string);
    }

    for (int i = 0; i < argc - 1; ++i) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
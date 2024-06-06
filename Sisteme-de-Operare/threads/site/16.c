// Scrieti un program C care primeste ca argumente la linia de comanda numere intregi. 
// Programul va calcula un vector de frecventa pentru cifrele zecimale. Pentru fiecare argument, 
// programul va crea un thread care numara aparitiile fiecarei cifre si adauga numarul la 
// pozitia corespunzatoare din vectorul de frecventa. Folositi sincronizare eficienta.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int freq[10]; 
pthread_mutex_t mutex;

void *handler(void *arg) {
    int number = *((int *)arg);
    free(arg);

    while (number) {
        pthread_mutex_lock(&mutex);
        freq[number % 10]++;
        pthread_mutex_unlock(&mutex);
        number /= 10;
    }

    return NULL;
}

int main(int argc, char **argv) { 
    pthread_mutex_init(&mutex, NULL);
    pthread_t t[argc - 1];

    for (int i = 1; i < argc; ++i) {
        int *number = (int *)malloc(sizeof(int));
        *number = atoi(argv[i]);

        pthread_create(&t[i - 1], NULL, handler, (void*)number);
    }

    for (int i = 1; i < argc; ++i) {
        pthread_join(t[i - 1], NULL);
    }

    pthread_mutex_destroy(&mutex);

    for (int i = 0; i < 10; ++i) {
        printf("The freq of digit %d is: %d\n", i, freq[i]);
    }

    return 0;
}

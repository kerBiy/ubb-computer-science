#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 5 

pthread_mutex_t mutex;
pthread_cond_t somn;

int scauneLibere = N, locTuns = 0, locNou = 0, clientNou = 0, clientTuns = 0;
int scaun[N];

void p(char* s) {
    printf("clientNou: %d, clientTuns: %d, locNou: %d, locTuns: %d, scauneLibere: %d, scaune: [ ", clientNou, clientTuns, locNou, locTuns, scauneLibere);

    for (int i = 0; i < N; i++) {
        printf("%d ", scaun[i]);
    }

    printf("]. %s\n", s);
}

void* client(void* a) {
    pthread_mutex_lock(&mutex);

    if (scauneLibere == 0) {
        p("Clientul pleaca netuns!");
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
    }

    scaun[locNou] = clientNou;
    locNou = (locNou + 1) % N;
    scauneLibere--;

    p("Clientul a ocupat loc");

    if (scauneLibere == N - 1) { 
        pthread_cond_signal(&somn);
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* frizer(void *a) {
    while (1) { 
        pthread_mutex_lock(&mutex);

        while(scauneLibere == N) {
            p("Frizerul doarme");
            pthread_cond_wait(&somn, &mutex);
        } 

        clientTuns = scaun[locTuns];
        scaun[locTuns] = 0;
        locTuns = (locTuns + 1) % N;
        scauneLibere++;

        p("Frizerul tunde");
        pthread_mutex_unlock(&mutex);
        sleep(2); 
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&somn, NULL);

    for (int i = 0; i < N; i++) {
        scaun[i] = 0;
    }

    pthread_t barber;
    pthread_create(&barber, NULL, frizer, NULL);

    while (1) {
        pthread_t customer;
        sleep(rand() % 3);
        clientNou++;
        pthread_create(&customer, NULL, client, NULL);
    }

    return 0;
}


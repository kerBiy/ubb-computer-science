#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5

sem_t mutex, somn;
int locTuns = 0, locNou = 0, clientNou = 0, clientTuns = 0;
int scaun[N];

void p(char* s) {
    printf("clientNou: %d, clientTuns: %d, locNou: %d, locTuns: %d, scaune: [ ",
           clientNou, clientTuns, locNou, locTuns);
    for (int i = 0; i < N; i++) printf("%d ", scaun[i]);
    printf(" ]. %s\n", s);
}

void* client(void* a) {
    sem_wait(&mutex);
    int so;
    sem_getvalue(&somn, &so);
    if (so == N) {
        p("Clientul pleaca netuns!");
        sem_post(&mutex);
        pthread_exit(NULL);
    }
    scaun[locNou] = clientNou;
    locNou = (locNou + 1) % N;
    p("Clientul a ocupat loc");
    sem_post(&somn);
    sem_post(&mutex);
}

void* frizer(void* a) {
    for (;;) {
        sem_wait(&mutex);
        int so;
        sem_getvalue(&somn, &so);
        if (so == 0) p("Frizerul doarme");
        sem_post(&mutex);
        sem_wait(&somn);
        sem_wait(&mutex);
        clientTuns = scaun[locTuns];
        scaun[locTuns] = 0;
        locTuns = (locTuns + 1) % N;
        p("Frizerul tunde");
        sem_post(&mutex);
        sleep(2);  // Atat dureaza "tunsul"
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&somn, 0, 0);
    for (int i = 0; i < N; scaun[i] = 0, i++);
    pthread_t barber;
    pthread_create(&barber, NULL, frizer, NULL);
    for (;;) {
        pthread_t customer;
        sleep(abs(rand() % 3));
        clientNou++;
        pthread_create(&customer, NULL, client, NULL);
    }
    return 0;
}

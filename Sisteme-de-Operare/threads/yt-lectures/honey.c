#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct timespec start;

pthread_mutex_t mutex;
pthread_cond_t cond;

int honey = 10;

int go() {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    float time = ((now.tv_sec - start.tv_sec) * 1000.0 + (now.tv_nsec - start.tv_nsec)/1000.0/1000.0);

    return time < 1000;
}

void *beeHandler(void *a) {
    while (go()) {
        pthread_mutex_lock(&mutex);
        printf("BEEEE\n");
        honey++; 
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *bearHandler(void *a) {
    while (go()) {
        pthread_mutex_lock(&mutex);
        
        if (honey > 0) {
            honey--;
        } else {
            pthread_cond_signal(&cond);
            printf("NO MORE HONEY!!!\n");
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *farmerHandler(void *a) {
    while (go()) {
        pthread_mutex_lock(&mutex);

        while (go() && honey > 0) {
            printf("Sleeping...\n");
            pthread_cond_wait(&cond, &mutex);
        }
        printf("I will add more\n");
        honey += 100;

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t[21];

    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t[0], NULL, farmerHandler, NULL);
    
    for (int i = 1; i < 20; ++i) {
        pthread_create(&t[i], NULL, beeHandler, NULL);
        pthread_create(&t[i + 1], NULL, bearHandler, NULL);
    }

    for (int i = 0; i < 21; ++i) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

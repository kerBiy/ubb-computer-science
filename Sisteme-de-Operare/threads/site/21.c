// Scrieti un program C care creeaza 2^N thread-uri care concureaza pana la linia de final 
// (N este argument la linia de comanda). Thread-urile trebuie sa treaca prin N puncte de control. 
// Punctul de control cu numarul X va permite sa treaca simultan prin el un numar de thread-uri 
// egal cu jumatate din numarul de thread-uri permise de punctul de control X - 1 (N >= X >=1). 
// Punctul de control cu numarul 0 (primul) va permite unui numar de 2^(N-1) thread-uri 
// sa treaca simultan.
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int barrier_size;
} pthread_barrier_t;

void pthread_barrier_init(pthread_barrier_t *barrier, int size) {
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->cond, NULL);
    barrier->count = 0;
    barrier->barrier_size = size;
}

void pthread_barrier_destroy(pthread_barrier_t *barrier) {
    pthread_mutex_destroy(&barrier->mutex);
    pthread_cond_destroy(&barrier->cond);
}

void pthread_barrier_wait(pthread_barrier_t *barrier) {
    pthread_mutex_lock(&barrier->mutex);
    barrier->count++;

    if (barrier->count >= barrier->barrier_size) {
        barrier->count = 0;
        pthread_cond_broadcast(&barrier->cond);
    } else {
        while (pthread_cond_wait(&barrier->cond, &barrier->mutex) != 0);
    }

    pthread_mutex_unlock(&barrier->mutex);
}

// PROBLEM CODE

typedef struct {
    int id;
    int n;
    sem_t *sems;
    pthread_barrier_t *barrier;
} pthread_data_t;

void *handler(void * arg) {
    pthread_data_t *d = (pthread_data_t *) arg;
    printf("Thread %d entered\n", d->id);
    pthread_barrier_wait(d->barrier);

    for (int i = 0; i < d->n; ++i) {
        sem_wait(&d->sems[i]);
        printf("Thread %d has arrived in %d location\n", d->id, i);

        int number = (rand() % 101 + 100) * 1000;
        usleep(number);
        sem_post(&d->sems[i]);
    }

    printf("Thread %d finished\n", d->id);
    
    free(d);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid args...");
        return 1;
    }

    int n = atoi(argv[1]);
    int twoPow = 1;

    for (int i = 0; i < n; ++i) {
        twoPow *= 2;
    }

    pthread_t t[twoPow];
    sem_t *sems = malloc(n * sizeof(sem_t));

    int step = 2;
    for (int i = 0; i < n; ++i) {
        sem_init(&sems[i], 0, twoPow / step);
        step *= 2;
    }
    
    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, n);

    for (int i = 0; i < n; ++i) {
        pthread_data_t *data = malloc(sizeof(pthread_data_t));
        data->id = i;
        data->n = n;
        data->sems = sems;
        data->barrier = &barrier;

        pthread_create(&t[i], NULL, handler, (void *) data);
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(t[i], NULL);
    }

    pthread_barrier_destroy(&barrier);

    for (int i = 0; i < n; ++i) {
        sem_destroy(&sems[i]);
    }
    free(sems);
    return 0;
}

// Scrieti un program C care primeste ca argumente la linia de comanda 2 numere: 
// N si M. Programul va simula o cursa intre N thread-uri care trebuie sa 
// treaca prin M puncte de control. Prin fiecare punct de control thread-urile
// trebuie sa treaca pe rand (nu se poate ca 2 thread-uri sa fie simultan in 
// acelasi punct de control). Fiecare thread care intra intr-un punct de control 
// va astepta intre 100 si 200 de milisecunde (usleep(100000) face ca un thread 
// sau proces sa astepte 100 de milisecunde) si va afisa un mesaj care va 
// contine numarul thread-ului si numarul punctului de control, apoi va iesi din 
// punctul de control. Fiecare thread va astepta pana cand toate thread-urile 
// au fost create.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
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

typedef struct {
    int id;
    int M;
    pthread_mutex_t *mutexes;
    pthread_barrier_t *barrier;
} Data;

void* handler(void* arg) {
    Data *d = (Data *) arg;
    printf("Thread %d has entered\n", d->id);
    pthread_barrier_wait(d->barrier);

    for (int i = 0; i < d->M; ++i) {
        pthread_mutex_lock(&d->mutexes[i]);
    
        printf("Thread %d has arrived at %d location\n", d->id, i);
        int number = (rand() % 101 + 100) * 1000;
        usleep(number);

        pthread_mutex_unlock(&d->mutexes[i]);
    }
   
    printf("Thread %d has finished\n", d->id);
    free(d);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("invalid args...");
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, n);
    pthread_t t[n];

    pthread_mutex_t *mutexes = (pthread_mutex_t*)malloc(m * sizeof(pthread_mutex_t));
    for (int i = 0; i < m; ++i) {
        pthread_mutex_init(&mutexes[i], NULL);
    }

    for (int i = 0; i < n; ++i) {
        Data *data = (Data*)malloc(sizeof(Data));
        data->id = i;
        data->M = m;
        data->mutexes = mutexes;
        data->barrier = &barrier;

        pthread_create(&t[i], NULL, handler, (void *) data);
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(t[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
    for (int i = 0; i < m; ++i) {
        pthread_mutex_destroy(&mutexes[i]);
    }
    free(mutexes);

    return 0;
}

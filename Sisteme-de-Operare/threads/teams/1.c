// 1. (1p) Scrieti un program C care creeaza N thread-uri, N primit ca
// argument la linia de comanda. Dupa creerea thread-urilor, thread-ul
// principal populeaza elementele unui array X cu N * N numere aleatorii,
// si le afiseaza. Cele N thread-uri isi incep executia doar dupa ce
// array-ul este complet populat. Fiecare thread alege aleator doua
// pozitii i si j din sir, si daca X[j] < X[i], interschimba cele doua valori.
// Thread-urile se executa pana in momentul in care s-au efectuat N comparari
// fara interschimbare. La final, thread-ul principal afiseaza sirul.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// My problem

typedef struct {
    int id;
    int n;
    int *nums;
    pthread_rwlock_t *rwlock;
    pthread_barrier_t *barrier;
} pthread_data_t;

void *workerHandler(void *arg) {
    pthread_data_t *d = (pthread_data_t *)arg;
    printf("Thread %d has entered\n", d->id);
    pthread_barrier_wait(d->barrier);
    printf("Thread %d started...\n", d->id);

    int count = 0;

    while (count < d->n) {
        int i = rand() % (d->n * d->n);
        int j = rand() % (d->n * d->n);

        int isValid = 0;
        pthread_rwlock_rdlock(d->rwlock);
        if (d->nums[i] > d->nums[j]) {
            isValid = 1;
        }
        pthread_rwlock_unlock(d->rwlock);

        if (isValid) {
            count = 0;
            pthread_rwlock_wrlock(d->rwlock);
            printf("Thread %d swaps %d with %d\n", d->id, d->nums[i],
                   d->nums[j]);
            int aux = d->nums[i];
            d->nums[i] = d->nums[j];
            d->nums[j] = aux;
            pthread_rwlock_unlock(d->rwlock);
        } else {
            count++;
        }
    }

    printf("Thread %d has finished\n", d->id);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Args invalid...");
        return 1;
    }
    srand(time(NULL));

    int n = atoi(argv[1]);
    int *nums = (int *)malloc(n * sizeof(int));

    pthread_barrier_t barrier;
    pthread_rwlock_t rwlock;
    pthread_t t[n];

    pthread_barrier_init(&barrier, n);
    pthread_rwlock_init(&rwlock, NULL);

    printf("Generating the array: ");
    for (int i = 0; i < n * n; ++i) {
        int number = rand() % 100;
        nums[i] = number;
        printf("%d ", nums[i]);
    }
    printf("\n");

    pthread_data_t *arg = (pthread_data_t *)malloc(n * sizeof(pthread_data_t));
    for (int i = 0; i < n; ++i) {
        arg[i].id = i;
        arg[i].n = n;
        arg[i].nums = nums;
        arg[i].rwlock = &rwlock;
        arg[i].barrier = &barrier;

        pthread_create(&t[i], NULL, workerHandler, (void *)&arg[i]);
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(t[i], NULL);
    }

    printf("The final array is: ");
    for (int i = 0; i < n * n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    pthread_barrier_destroy(&barrier);
    pthread_rwlock_destroy(&rwlock);

    free(arg);
    free(nums);
    return 0;
}
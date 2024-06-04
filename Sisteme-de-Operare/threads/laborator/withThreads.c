#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100000000
#define THREADS 16

int *vec = (int*) malloc(sizeof(int) * SIZE);
int res[THREADS];
int min = SIZE;

void *f(void *a) {
    int id = *(int*)a;
    free(a);

    int st = id * SIZE / THREADS;
    int dr = st + SIZE / THREADS;

    int minim = SIZE;
    for (int i = st; i < dr - 1; ++i) {
        if (vec[i] < minim) {
            minim = vec[i];
        }
    }
    
    res[id] = minim;

    return NULL;
}

int main() {
    srand(time(NULL));

    struct timespec t0, t1;

    for (int i = 0; i < SIZE; ++i) {
        vec[i] = rand();
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t0);
  
    pthread_t t[THREADS];
    for (int i = 0; i < THREADS; ++i) {
        int *id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&t[i], NULL, f, id);
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(t[i], NULL);
    }

    int mini = SIZE;
    for (int i = 0; i < THREADS; ++i) {
        if (res[i] < mini) {
            mini = res[i];
        }
    }

    printf("The min is: %d\n", mini);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);

    double delta = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                    (t1.tv_nsec - t0.tv_nsec) / 1000.0 / 1000.0;

    printf("The time is: %f\n", delta);
    
    return 0;
}

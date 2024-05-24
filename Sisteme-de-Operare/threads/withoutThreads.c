#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100000000

int main() {
    srand(time(NULL));

    struct timespec t0, t1;

    int *vec = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        vec[i] = rand();
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t0);
    
    int min = SIZE;
    for (int i = 0; i < SIZE; ++i) {
        if (vec[i] < min) {
            min = vec[i];    
        }
    }
   
    printf("The min is: %d\n", min);
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);

    double delta = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                    (t1.tv_nsec - t0.tv_nsec) / 1000.0 / 1000.0;

    printf("The time is: %f\n", delta);
    free(vec);
    return 0;
}

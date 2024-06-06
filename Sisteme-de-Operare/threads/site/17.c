#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    pthread_mutex_t *mutex;
    pthread_cond_t *cond;
    int *array;
    int *current;
    int n;
} Argument;

void *evenHandler(void *arg) {
    Argument *a = (Argument *)arg;

    while (1) {
        pthread_mutex_lock(a->mutex);

        while (*a->current % 2 != 0 && *a->current < a->n) {
            pthread_cond_wait(a->cond, a->mutex);
        }

        if (*a->current >= a->n) {
            pthread_mutex_unlock(a->mutex);
            pthread_cond_signal(a->cond);
            return NULL;
        }

        int number = (rand() % 100) * 2;
        a->array[*a->current] = number;
        *a->current += 1;

        printf("Even Thread: ");
        for (int i = 0; i < *a->current; ++i) {
            printf("%d ", a->array[i]);
        }
        printf("\n");

        pthread_mutex_unlock(a->mutex);
        pthread_cond_signal(a->cond);
    }

    return NULL;
}

void *oddHandler(void *arg) {
    Argument *a = (Argument *)arg;

    while (1) {
        pthread_mutex_lock(a->mutex);

        while (*a->current % 2 != 1 && *a->current < a->n) {
            pthread_cond_wait(a->cond, a->mutex);
        }

        if (*a->current >= a->n) {
            pthread_mutex_unlock(a->mutex);
            pthread_cond_signal(a->cond);
            return NULL;
        }

        int number = (rand() % 100) * 2 + 1;
        a->array[*a->current] = number;
        *a->current += 1;

        printf("Odd Thread: ");
        for (int i = 0; i < *a->current; ++i) {
            printf("%d ", a->array[i]);
        }
        printf("\n");

        pthread_mutex_unlock(a->mutex);
        pthread_cond_signal(a->cond);
    }

    return NULL;
}

void init_arg(Argument *arg, pthread_mutex_t *mutex, pthread_cond_t *cond,
              int n, int *array, int *current) {
    arg->mutex = mutex;
    arg->cond = cond;
    arg->n = n;
    arg->array = array;
    arg->current = current;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 1) {
        fprintf(stderr, "The number should be at least 1");
        return 1;
    }

    srand(time(NULL));

    int *array = (int *)malloc(n * sizeof(int));
    int current = 0;

    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t t[2];
    Argument arg[2];

    init_arg(&arg[0], &mutex, &cond, n, array, &current);
    init_arg(&arg[1], &mutex, &cond, n, array, &current);

    pthread_create(&t[0], NULL, evenHandler, (void *)&arg[0]);
    pthread_create(&t[1], NULL, oddHandler, (void *)&arg[1]);

    for (int i = 0; i < 2; ++i) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    free(array);
    return 0;
}

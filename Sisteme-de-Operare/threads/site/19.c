// Scrieti un program C care primeste ca argument la linia de comanda un intreg
// N, apoi citeste de la tastatura N intregi si ii stocheaza intr -un sir.
// Programul calculeaza suma tuturor intregilor cititi folosind thread -uri
// care respecta ierarhia prezentata in imagine.Pentru orice N, sirul de intregi
// trebuie extins cu valori de 0 astfel incat numarul de elemente din sir sa
// fie o putere a lui 2(fie numarul acesta M).Numarul de thread - uri necesare
// va fi M - 1, vom aloca cate un ID intre 1 si M - 1 fiecarui thread.
// Conform imaginii, thread - urile cu ID >= M / 2 vor calcula suma a doua
// numere de pe pozitii consecutive din sir.Thread urile cu ID < M / 2 trebuie
// sa astepte dupa alte 2 thread - uri si apoi vor aduna rezultatul produs de
// cele 2 thread - uri.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int start;
    int end;
    int *result;
} Data;

void *sum_thread(void *arg) {
    Data *data = (Data *)arg;
    int start = data->start;
    int end = data->end;

    if (start == end) {
        *(data->result) = data->array[start];
        return NULL;
    }

    int mid = (start + end) / 2;

    int left_result = 0;
    int right_result = 0;

    Data left_data = {data->array, start, mid, &left_result};
    pthread_t left_thread;
    pthread_create(&left_thread, NULL, sum_thread, &left_data);

    Data right_data = {data->array, mid + 1, end, &right_result};
    pthread_t right_thread;
    pthread_create(&right_thread, NULL, sum_thread, &right_data);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    *(data->result) = left_result + right_result;

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        fprintf(stderr, "N must be a positive integer\n");
        return 1;
    }

    int twoPower = 1;
    while (twoPower < N) {
        twoPower *= 2;
    }

    int *array = (int *)calloc(twoPower, sizeof(int));
    printf("Enter %d integers:\n", N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int result = 0;
    Data root_data = {array, 0, twoPower - 1, &result};

    pthread_t root_thread;
    pthread_create(&root_thread, NULL, sum_thread, &root_data);
    pthread_join(root_thread, NULL);

    printf("Sum: %d\n", result);

    free(array);
    return 0;
}

#include <stdio.h>
#include <pthread.h>

void *f(void *a) {
    printf("The thread nr: %d\n", *(int*)a);
    return NULL;
}

int main() {
    const int n = 10;

    int number[n];
    pthread_t t[n];

    for (int i = 0; i < n; ++i) {
        number[i] = i;
        pthread_create(&t[i], NULL, f, &number[i]);
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(t[i], NULL);
    } 

    return 0;
}

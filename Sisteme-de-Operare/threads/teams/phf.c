// Scrieti un program care creaza 2*N thread-uri, unde N este primit ca argument
// la linia de comanda. Fiecare pereche de 2 thread-uri joaca
// piatra-foarfeca-hartie, si fiecare thread incepe cu a avea 3 vieti.
// De fiecare data cand un thread pierde, i se scade o viata. La doua
// castiguri consecutive, primeste o viata in plus. Cand un thread
// ramane fara vieti, jocul sau si a perechii sale se termina.
// Daca oricare din jucatori ajunge la a avea 5 vieti,
// este declarat castigator absolut, si toate jocurile se termina.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_LIVES 3
#define MAX_LIVES 5

typedef struct {
    int id;
    int lives;
    int consecutive_wins;
    pthread_mutex_t *mutex;
    pthread_cond_t *cond;
    int *game_over;
} pthread_data_t;

void *handler(void *arg) {
    pthread_data_t *data = (pthread_data_t *)arg;
    int other_choice;
    int my_choice;
    srand(time(NULL) * data->id);

    while (*data->game_over == 0) {
        my_choice = rand() % 3;
        pthread_mutex_lock(data->mutex);
        other_choice = (rand() % 3);
        printf("Thread %d vs Thread %d: %d vs %d\n", data->id, (data->id + 1),
               my_choice, other_choice);

        if (my_choice == other_choice) {
            printf("Thread %d and Thread %d: Draw\n", data->id, (data->id + 1));
        } else if ((my_choice == 0 && other_choice == 2) ||
                   (my_choice == 1 && other_choice == 0) ||
                   (my_choice == 2 && other_choice == 1)) {
            printf("Thread %d wins against Thread %d\n", data->id,
                   (data->id + 1));
            data->consecutive_wins++;
            if (data->consecutive_wins == 2) {
                data->lives++;
                data->consecutive_wins = 0;
            }
            if (data->lives == MAX_LIVES) {
                printf("Thread %d wins the game!\n", data->id);
                *(data->game_over) = 1;
            }
        } else {
            printf("Thread %d loses against Thread %d\n", data->id,
                   (data->id + 1));
            data->consecutive_wins = 0;
            data->lives--;
            if (data->lives == 0) {
                printf("Thread %d is out of lives.\n", data->id);
                *(data->game_over) = 1;
            }
        }

        pthread_cond_broadcast(data->cond);
        pthread_mutex_unlock(data->mutex);

        usleep(100000);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Invalid args.");
        return 1;
    }

    int n = atoi(argv[1]);
    pthread_t t[2 * n];
    pthread_data_t arg[2 * n];
    pthread_mutex_t mutex;
    pthread_cond_t cond;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    int game_over = 0;

    for (int i = 0; i < 2 * n; i++) {
        arg[i].id = i;
        arg[i].lives = INITIAL_LIVES;
        arg[i].consecutive_wins = 0;
        arg[i].mutex = &mutex;
        arg[i].cond = &cond;
        arg[i].game_over = &game_over;
        pthread_create(&t[i], NULL, handler, &arg[i]);
    }

    for (int i = 0; i < 2 * n; i++) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_rwlock_t rwl;

struct Node {
    int value;
    struct Node *next;
};

void addNode(struct Node *head, struct Node *new_node) {
    struct Node *curr = head;
    
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    curr->next = new_node;
}

int main() {
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->value = 1;
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->value = 2;
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->value = 3;

    first->next = second;
    second->next = third;
    third->next = NULL;
    
    pthread_t read;

    pthread_rwlock_init(&rwl, NULL);

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->value = 5;
    new->next = NULL;
    addNode(first, new);

    struct Node *current = first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    free(first);
    free(second);
    free(third);
    free(new);

    return 0;
}

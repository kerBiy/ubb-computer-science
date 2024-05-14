#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void f(int sgn) {
    char str[32];
    printf("Are you sure you want to stop [y/N]?\n");
    scanf("%s", str);

    if (strncmp(str, "y", 32) == 0) {
        exit(0);
    }
}

int main() {
    signal(SIGINT, f);
    while (1);
    return 0;
}

// Scrieti un program care citeste n numere de la tastatura si tipareste suma lor.

#include <stdio.h>

int main()
{
    int n, sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }

    printf("Suma este: %d\n", sum);

    return 0;
}
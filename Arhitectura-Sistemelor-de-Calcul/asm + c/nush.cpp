#include <stdio.h>
#include <string.h>

int binaryToDecimal(char *binaryNumber)
{
    int length = strlen(binaryNumber);
    int decimalNumber = 0, twoPower = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (binaryNumber[i] == '1')
            decimalNumber = decimalNumber + twoPower;

        twoPower = twoPower * 2;
    }

    return decimalNumber;
}

int main()
{
    int n;
    printf("Introduceti numarul de numere in baza 2: ");
    scanf("%d", &n);

    char binaryNumber[100];

    for (int i = 0; i < n; ++i)
    {
        printf("Introduceti numarul in baza 2: ");
        scanf("%s", binaryNumber);

        int decimal_number = binaryToDecimal(binaryNumber);

        printf("Numarul in baza 16: %x\n", decimal_number);
    }

    return 0;
}

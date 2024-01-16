#include <stdio.h>
#include <string.h>

int binaryToDecimal(char *binaryNumber);

int main()
{
    char binaryNumber[100];

    while (1)
    {
        printf("Introduceti numarul in baza 2: ");
        scanf("%s", binaryNumber);
        
        if (strcmp(binaryNumber, "x") == 0)
            break;

        int decimal_number = binaryToDecimal(binaryNumber);

        printf("Numarul in baza 16: %x\n", decimal_number);
    }

    return 0;
}
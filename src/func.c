#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void read_dictionary(char* filename, char words[RSIZ][LSIZ], int* n)
{
    int count = 0;
    FILE* fptr = NULL;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Не получилось открыть файл\n");
        exit(1);
    }

    fscanf(fptr, "%d\n", &count);
    for (int i = 0; i < count; i++) {
        fscanf(fptr, "%s\n", words[i]);
    }
    *n = count;

    fclose(fptr);
}

void hangman(int i)
{
    system("clear");
    switch (i) {
    case 0:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 1:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||    O ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 2:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO ", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 3:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 4:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 5:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||     %c", '\\');
        printf("\n\t||      ");
        break;
    case 6:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||   / %c", '\\');
        printf("\n\t||      ");
        break;
    default:
        printf("Ошибка. Количество неверно введёных букв не може быть больше "
               "6");
    }
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

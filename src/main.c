#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    char list[RSIZ][LSIZ]; // Список слов из словаря
    char *word;
    int len; // Длина слова
    char vis_let[20] ={' '};
    int trigger = 0; 
    char guess;
    int right = 0; // Количсетво верно введённых слов
    int strikes = 0; // Количество допущенных ошибок
    char incor_let[30] = {' '};
    int choice;

    srand(time(0));
    printf("1. Играть\n");
    printf("2. Выход \n");
    scanf("%d", &choice);
    if(choice == 2)
    {
        exit(1);
    }
    while (choice != 1 || choice != 2)
    {
        printf("Неверный ввод попробуйте снова: ");
        scanf("%d", &choice);                 
    }

    printf("Загадываемое слово будет длиной... \n");
    printf("1) 3-5 букв \n");
    printf("2) 6-9 букв \n");
    printf("3) 10-12 букв \n");

    scanf("%d", &choice);
    while (choice < 1 || choice > 3)
    {
        printf("Неверный ввод попробуйте снова: ");
        scanf("%d", &choice);                 
    }
    switch (choice)
    {
    case 1:
        read_dictionary("dictionary1.txt", list, &n);
        break;
    case 2:
        read_dictionary("dictionary2.txt", list, &n);
        break;
    case 3:
        read_dictionary("dictionary3.txt", list, &n);
        break;
    }

    int r = getrand(0, n);
    n = 0;
    word = list[r];
    //printf("%s\n", word);
    len = strlen(word);
    //printf("%d\n", len);

    for (i = 0; i < len; i++)
    {
        vis_let[i] = '.';
    }
    vis_let[len] = '\0';

    printf("%s\n", vis_let);

    for (j = 0; j < 26; j++)
    {
        if (right == len)
        {
            printf("\n\nЭто было слово: %s\n", word);
            printf("\nПобеда!\n");
            break;
        }

        hangman(strikes);

        if (strikes == 6)
        {
            printf("\n\nnЭто было слово: %s\n", word);
            printf("\n\nВы проиграли.\n");
            break;
        }

        printf("\n\n\n\n%s", vis_let);
        printf("\n Неверные буквы: %s", incor_let);

        printf("\n\nВведите букву:");
        scanf(" %c", &guess);

        for (i = 0; i < len; i++)
        {
            if (word[i] == guess)
            {
                vis_let[i] = guess; 
                trigger++;
                right++;
            }
        }

        if (trigger == 0)
        {
            strikes++;
            incor_let[n++] = guess;
        }

        trigger = 0;
    }
    return 0;
}
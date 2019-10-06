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
    int mistakes = 0; // Количество неверно введённых за ход букв
    char guess;
    int right = 0; // Количсетво верно введённых слов
    int strikes = 0; // Количество допущенных ошибок

    srand(time(0));
    read_dictionary("dictionary1.txt", list, &n);
    int r = getrand(0, n);
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

        printf("\n\nВведите букву:");
        scanf(" %c", &guess);

        for (i = 0; i < len; i++)
        {
            if (word[i] == guess)
            {
                vis_let[i] = guess; 
                mistakes++;
                right++;
                printf("\n\n\n\n%d", right);
            }
        }

        if (mistakes == 0)
        {
            strikes++;
        }

        mistakes = 0;
    }
    return 0;
}
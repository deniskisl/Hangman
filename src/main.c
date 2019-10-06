#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
    int i = 0;
    int n = 0;
    char list[RSIZ][LSIZ];
    char *word;
    int len;

    srand(time(0));
    read_dictionary("dictionary1.txt", list, &n);
    int r = getrand(0, n);
    word = list[r];
    printf("%s\n", word);
    len = strlen(word);
    printf("%d\n", len);
    return 0;
}
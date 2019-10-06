#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
    int i = 0;
    int n = 0;
    char words[RSIZ][LSIZ];
    char *word;

    srand(time(0));
    read_dictionary("dictionary1.txt", words, &n);
    int r = getrand(0, n);
    word = words[r];
    printf("%s\n", word);
    return 0;
}
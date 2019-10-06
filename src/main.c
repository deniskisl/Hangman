#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
    int i = 0;
    int n = 0;
    char words[RSIZ][LSIZ];

    read_dictionary("dictionary1.txt", words, &n);
    for(i; i < n ;i++)
    {
    printf("%s\n", words[i]);
    }
    
    return 0;
}
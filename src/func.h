#define LSIZ 20
#define RSIZ 100

void read_dictionary(char *filename, char words[RSIZ][LSIZ], int *n);
void hangman(int i);
int getrand(int min, int max);
#include "../src/func.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(getrand, rand_test) // Проверка на интервале положительных чисел и 0
{
    const int exp1 = 0;
    const int exp2 = 20;

    int v1 = getrand(exp1, exp2);

    ASSERT_INTERVAL(exp1, exp2, v1);
}

CTEST(getrand, rand_test2) // Проверка на интервале положительных чисел
{
    const int exp1 = 1;
    const int exp2 = 20;

    int v2 = getrand(exp1, exp2);

    ASSERT_INTERVAL(exp1, exp2, v2);
}

CTEST(getrand,
      rand_test3) // Проверка на интервале интервале отрицательных чисел и 0
{
    const int exp1 = -10;
    const int exp2 = 0;

    int v3 = getrand(exp1, exp2);

    ASSERT_INTERVAL(exp1, exp2, v3);
}

CTEST(getrand, rand_test4) // Проверка на интервале орицательных чисел
{
    const int exp1 = -10;
    const int exp2 = -1;

    int v4 = getrand(exp1, exp2);

    ASSERT_INTERVAL(exp1, exp2, v4);
}

/*...................................................................................*/

CTEST(read, num_words)
{
    const int exp = 3;
    char list[RSIZ][LSIZ];
    int v1;

    read_dictionary("dictionaries/test_dictionary.txt", list, &v1);

    ASSERT_EQUAL(exp, v1);
}

CTEST(read, read_word1)
{
    char list[RSIZ][LSIZ];
    int v1;
    char exp[3] = {'b', 'a', 'g'};

    read_dictionary("dictionaries/test_dictionary.txt", list, &v1);

    ASSERT_STR(exp, list[0]);
}

CTEST(read, read_word2)
{
    char list[RSIZ][LSIZ];
    int v1;
    char exp[3] = {'r', 'u', 'n'};

    read_dictionary("dictionaries/test_dictionary.txt", list, &v1);

    ASSERT_STR(exp, list[1]);
}

CTEST(read, read_word3)
{
    char list[RSIZ][LSIZ];
    int v1;
    char exp[3] = {'s', 'u', 'n'};

    read_dictionary("dictionaries/test_dictionary.txt", list, &v1);

    ASSERT_STR(exp, list[2]);
}

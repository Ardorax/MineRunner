/*
** EPITECH PROJECT, 2021
** give malloc str
** File description:
** return a ptr
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *give_malloc_str(char *str)
{
    char *res = malloc(my_strlen(str) + 1);
    int count = -1;
    do {
        count++;
        res[count] = str[count];
    } while (str[count] != 0);

    return (res);
}

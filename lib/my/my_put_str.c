/*
** EPITECH PROJECT, 2021
** my put str
** File description:
** put an str
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_put_str(char *str, int count)
{
    write(count, str, my_strlen(str));
}

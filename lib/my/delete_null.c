/*
** EPITECH PROJECT, 2021
** delete null
** File description:
** dont show zero
*/

char *hide_null(char *str)
{
    while (str[0] == '0' && str[1] != 0)
        str++;
    return (str);
}

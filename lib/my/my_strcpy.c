/*
** EPITECH PROJECT, 2021
** My strcpy
** File description:
** A string copy
*/

char *my_strcpy(char *dest, char const *src)
{
    int nb_char = 0;
    while (src[nb_char] != '\0') {
        dest[nb_char] = src[nb_char];
        nb_char++;
    }
    dest[nb_char] = '\0';
    return (dest);
}

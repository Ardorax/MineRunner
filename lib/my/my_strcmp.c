/*
** EPITECH PROJECT, 2021
** My strcmp
** File description:
** Not sure of this one
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int nb_char = 0;
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    while (s1[nb_char] != '\0' && s1[nb_char] == s2[nb_char]) {
        nb_char++;
    }
    return (s1[nb_char] - s2[nb_char]);
}

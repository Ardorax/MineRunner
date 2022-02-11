/*
** EPITECH PROJECT, 2021
** My putstr
** File description:
** len(ç in py
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != 0) {
        count++;
    }

    return (count);
}

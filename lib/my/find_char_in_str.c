/*
** EPITECH PROJECT, 2021
** find_char_is_str
** File description:
** find a char in a str
*/

int char_in_str(char c, char *str)
{
    int count = 0;
    while (str[count] != 0) {
        if (str[count] == c)
            return (1);
        count++;
    }
    return (0);
}

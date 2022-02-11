/*
** EPITECH PROJECT, 2021
** start game
** File description:
** dfs
*/

#include "../include/my.h"

int start(int ac, char **av)
{
    int infinite = 0;
    if (ac == 3) {
        if (av[2][0] == '-' && av[2][1] == 'i')
            infinite = 1;
    }
    define_handler(av[1], infinite);
}

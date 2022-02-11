/*
** EPITECH PROJECT, 2021
** create obstacles
** File description:
** create obstacles
*/

#include "../include/my.h"

int put_block(params_t *params, int x, int y, char block)
{
    if (params->map[x][y] == ' ')
        params->map[x][y] = block;
}

int create_obstacle(params_t *params)
{
    for (int count = 0; params->map[27][count] != '\n'; count++) {
        srand(count * params->distance);
        if (params->map[27][count] == '4' &&
        rand() % (3 - params->difficulty) == 0)
            return (create_tree(params, count));
    }
}

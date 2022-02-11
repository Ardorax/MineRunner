/*
** EPITECH PROJECT, 2021
** put tree
** File description:
** put a tree in map
*/

#include "../include/my.h"

int create_oak(params_t *params, int y_pos)
{
    int count;
    for (count = y_pos; count < y_pos + 4; count++)
        params->map[27][count] = '5';
    int x;
    for (x = 25; x < 30; x++) {
        put_block(params, x, count, '6');
        if (x != 27)
            put_block(params, x, count - 1, '6');
    }
    for (x = 26; x < 29; x++)
        put_block(params, x, count + 1, '6');
}

int create_spruce(params_t *params, int y_pos)
{
    int count;
    for (count = y_pos; count < y_pos + 2; count++)
        params->map[27][count] = '5';
    int x;
    for (x = 25; x < 30; x++)
        put_block(params, x, count, '6');
    for (x = 26; x < 29; x++)
        put_block(params, x, count + 1, '6');
    for (x = 25; x < 30; x++)
        put_block(params, x, count + 2, '6');
    for (x = 26; x < 29; x++)
        put_block(params, x, count + 3, '6');
    put_block(params, 27, count + 4, '6');
}

int create_cactus(params_t *params, int y_pos)
{
    for (int count = y_pos; count < y_pos + 3 + rand() % 2; count++)
        params->map[27][count] = '7';
}

int create_tree(params_t *params, int y_pos)
{
    switch (params->current_biome) {
    case 0:
        return (create_oak(params, y_pos));
    case 1:
        return (create_spruce(params, y_pos));
    case 2:
        return (create_cactus(params, y_pos));
    default:
        break;
    }
}

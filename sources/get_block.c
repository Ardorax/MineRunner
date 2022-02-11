/*
** EPITECH PROJECT, 2021
** get block
** File description:
** 0-3 blocks, 4-6tree, 7-9anim
*/

#include "../include/my.h"

int alternate(int anim)
{
    anim = anim % 38;
    if (anim > 19)
        anim = 38 - anim;
    return (anim);
}

sfIntRect get_anim_block(char b, int anim)
{
    if (b >= '!' && b <= '$')
        return ((sfIntRect){192, 64, 16, 16});
    switch (b) {
    case '8':
        return ((sfIntRect){208, 112, 16, 16});
    case 'l':
        return ((sfIntRect){256, 0 + 16 * alternate(anim), 16, 16});
    case 'w':
        return ((sfIntRect){272, 0 + 16 * (anim % 32), 16, 16});
    case 'f':
        return ((sfIntRect){288, 0 + 16 * (anim % 32), 16, 16});
    default:
        return ((sfIntRect){-10, 0, 16, 16});
    }
}

sfIntRect get_block(char b, int anim, int biome)
{
    switch (b) {
    case '0':
        return ((sfIntRect){192 + 16 * biome, 64, 16, 16});
    case '1':
        return ((sfIntRect){192 + 16 * biome, 48, 16, 16});
    case '2':
        return ((sfIntRect){192 + 16 * biome, 32, 16, 16});
    case '3':
        return ((sfIntRect){192 + 16 * biome, 16, 16, 16});
    case '4':
        return ((sfIntRect){192 + 16 * biome, 0, 16, 16});
    case '5':
        return ((sfIntRect){192 + 16 * biome, 80, 16, 16});
    case '6':
        return ((sfIntRect){192 + 16 * biome, 96, 16, 16});
    case '7':
        return ((sfIntRect){192, 112, 16, 16});
    default:
        return (get_anim_block(b, anim));
    }
}

int get_block_score(char b)
{
    switch (b) {
    case '8':
        return (10);
    case '4':
        return (-10);
    default:
        return (-1);
    }
}

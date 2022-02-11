/*
** EPITECH PROJECT, 2021
** draw
** File description:
** draw obj
*/

#include "../include/my.h"

int draw_in_map(params_t *params, sfVector2f pos, int col, int line)
{
    sfIntRect rect = get_block(params->map[col][line], sfView_getCenter(
        params->view).x / (params->speed * 10), params->current_biome);
    if (rect.top == -10)
        return (0);
    sfSprite_setPosition(params->cube_sp, pos);
    sfSprite_setTextureRect(params->cube_sp, rect);
    sfRenderWindow_drawSprite(params->window, params->cube_sp, NULL);
}

// Draw one cube
int draw_object(params_t *params)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {224, 0, 16, 16};
    sfSprite_setTextureRect(params->cube_sp, rect);
    params->current_biome = params->start_biome;
    int line = 0;
    for (int column = 0; column < 25; column++) {
        pos.x = column * 16 * BLOCK_SIZE + (((int)sfView_getCenter(
        params->view).x / (16 * BLOCK_SIZE)) * 16 * BLOCK_SIZE ) - 1920 / 2;
        if (params->map[column][0] >= '!' && params->map[column][0] <= '$')
            params->current_biome = params->map[column][0] - '!';
        for (line = 0; line < 13 && params->map[column][line] != '\n' &&
        params->map[column][line] != '\0'; line++) {
            pos.y = 1080 - (line + 1) * 16 * BLOCK_SIZE;
            draw_in_map(params, pos, column, line);
        }
    }
}

int draw_player(params_t *params)
{
    sfRenderWindow_drawSprite(params->window, params->obj_sp, NULL);
}

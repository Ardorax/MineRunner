/*
** EPITECH PROJECT, 2021
** player
** File description:
** player handling
*/

#include "../include/my.h"
#include <math.h>

int update_anim(params_t *params)
{
    if (params->isjumping) {
        if (params->player_attraction < 0)
            sfSprite_setTextureRect(params->obj_sp, \
            (sfIntRect){0, 24 + 48 * params->character, 24, 24});
        else
            sfSprite_setTextureRect(params->obj_sp, \
            (sfIntRect){24, 24 + 48 * params->character, 24, 24});
        return (0);
    }
    params->player_anim++;
    if (params->player_anim > 10) {
        params->player_anim = 0;
        params->player_rect.left += 24;
        if (params->player_rect.left == 24 * 4) {
            params->player_rect.left = 0;
        }
        sfSprite_setTextureRect(params->obj_sp, params->player_rect);
    }
}

// Function to draw bound (DEBUG)
int draw_bound(params_t *params)
{
    sfVector2f all_pos[4] = {params->upleft, {params->downright.x,
    params->upleft.y}, params->downright, {params->upleft.x,
    params->downright.y}};
    for (int count = 0; count < 4; count++) {
        sfCircleShape_setPosition(params->bound_circle, all_pos[count]);
        if (params->collision[count]) {
            sfCircleShape_setFillColor(params->bound_circle, sfRed);
        } else {
            sfCircleShape_setFillColor(params->bound_circle, sfWhite);
        }
        sfCircleShape_setRadius(params->bound_circle, 2);
        sfRenderWindow_drawCircleShape(params->window, params->bound_circle,
        NULL);
    }
}

int set_bound(params_t *params)
{
    params->upleft = sfSprite_getPosition(params->obj_sp);
    params->downright = params->upleft;
    params->upleft.x += 6 * BLOCK_SIZE;
    params->upleft.y += 8 * BLOCK_SIZE + 1;
    params->downright.x += 16 * BLOCK_SIZE;
    params->downright.y += 25 * BLOCK_SIZE;
}

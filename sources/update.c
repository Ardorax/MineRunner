/*
** EPITECH PROJECT, 2021
** update
** File description:
** Calcul update of frame
*/

#include "../include/my.h"

int update_background(params_t *params)
{
    params->bg_pos.x += params->speed - 0.5;
    if (sfView_getCenter(params->view).x - 1920 - 960 >= params->bg_pos.x) {
        params->bg_pos.x += 1920;
    }
}

// Control the texture and test collision problem
int update_player(params_t *params)
{
    update_anim(params);
    set_bound(params);
    if (!sfRenderWindow_mapCoordsToPixel(params->window,
    params->downright, params->view).x) {
        kill_player(params);
        return (0);
    }
    corner_collide(params);
    main_collide(params);
    if (params->collision[0] || params->upleft.y >= 1080) {
        kill_player(params);
        return (0);
    }
    sfSprite_setPosition(params->obj_sp, \
    (sfVector2f){sfView_getCenter(params->view).x + params->player_x, \
    params->player_y});
}

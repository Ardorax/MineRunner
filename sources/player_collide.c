/*
** EPITECH PROJECT, 2021
** player collide
** File description:
** player
*/

#include "../include/my.h"

// Put the player on the floor if gravity is too strong
int reset_y(params_t *params)
{
    float tmp = params->player_y;
    if (tmp - params->player_y - (int){tmp - params->player_y} > 0.5 ||
    tmp - params->player_y - (int){tmp - params->player_y} == 0)
        params->player_y = (int)(params->player_y / (int)(16 * BLOCK_SIZE)) *
        (16 * BLOCK_SIZE);
    else
        params->player_y = (int)(params->player_y / (int)(16 * BLOCK_SIZE)) *
        (16 * BLOCK_SIZE) + 1;
    sfSprite_setPosition(params->obj_sp, (sfVector2f){sfView_getCenter(\
    params->view).x + params->player_x, params->player_y});
    if (params->player_attraction > 30)
        sfSound_play(params->sound_manager->sound[3]);
    params->player_attraction = 0.5;
    params->isjumping = 0;
}

int cancel_jump_ground(params_t *params)
{
    set_bound(params);
    corner_collide(params);
    if ((params->collision[2] == 1 || params->collision[3] == 1) &&
    params->player_attraction > 0) {
        reset_y(params);
    }
}

void end_of_ride(params_t *params)
{
    set_bound(params);
    corner_collide(params);
    if (params->collision[3]) {
        reset_y(params);
    } else {
        params->hand_pos[1] = 999;
    }
}

// Wall collision
int floor_wall_collide(params_t *params)
{
    if (params->collision[1]) {
        params->player_x -= params->speed;
        params->player_attraction = 0.5;
        params->player_y += 5;
        sfSprite_setPosition(params->obj_sp, (sfVector2f){sfView_getCenter(\
        params->view).x + params->player_x, params->player_y});
        end_of_ride(params);
    } else if ((params->collision[2] == 0 && params->collision[3] == 0) ||
    params->player_attraction < 0) {
        params->player_y += params->player_attraction;
        sfSprite_setPosition(params->obj_sp, \
        (sfVector2f){sfView_getCenter(params->view).x + params->player_x, \
        params->player_y});
        if (params->collision[2] == 0 && params->collision[3] == 0 &&
        params->player_attraction > 0)
            cancel_jump_ground(params);
        params->player_attraction += 1.9;
        if (params->player_attraction > (int){16 * BLOCK_SIZE} - 10)
            params->player_attraction = (int){16 * BLOCK_SIZE} - 10;
    }
}

int main_collide(params_t *params)
{
    if (params->collision[1] && params->player_attraction < 0) {
        params->player_y += params->player_attraction;
        params->player_attraction += 1.7;
    } else {
        floor_wall_collide(params);
    }
}

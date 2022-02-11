/*
** EPITECH PROJECT, 2021
** collision
** File description:
** which should collide
*/

#include "../include/my.h"

int kill_player_collision(params_t *params, sfIntRect corner)
{
    if (params->map[corner.width][corner.top] == '7') {
        kill_player(params);
    }
    if (params->map[corner.width][corner.height] == 'f') {
        kill_player(params);
    }
    if (params->map[corner.width][corner.top] == 'f' ||
    params->map[corner.width][corner.top] == 'l') {
        kill_player(params);
    }
    if (params->map[corner.left][corner.top] == 'l') {
        kill_player(params);
    }
}

int set_collision(params_t *params, sfIntRect corner)
{
    char *blk = " 4flw";
    if (corner.top >= 13 || corner.top < 0) {
        params->collision[0] = 0;
        params->collision[1] = 0;
    } else {
        params->collision[0] = (char_in_str(params->map[corner.left]
        [corner.top], blk)) ? 0 : 1;
        params->collision[1] = (char_in_str(params->map[corner.width]
        [corner.top], blk)) ? 0 : 1;
    }
    if (corner.height < 0 || corner.height >= 13) {
        params->collision[2] = 0;
        params->collision[3] = 0;
    } else {
        params->collision[2] = (char_in_str(params->map[corner.width]
        [corner.height], blk)) ? 0 : 1;
        params->collision[3] = (char_in_str(params->map[corner.left]
        [corner.height], blk)) ? 0 : 1;
    }
    kill_player_collision(params, corner);
}

int corner_collide(params_t *params)
{
    char *blk = " 4flw";
    sfVector2f view = sfView_getCenter(params->view);
    int block = 16 * BLOCK_SIZE;
    int up = (params->upleft.y - view.y - 540) / (int)(-16 * BLOCK_SIZE);
    int left = (params->upleft.x - view.x + 960 +
    (params->advencement)) / (block);
    int down = (params->downright.y - view.y - 540) / (int)(-16 * BLOCK_SIZE);
    int right = (params->downright.x - view.x + 960 +
    (params->advencement)) / (block);
    set_collision(params, (sfIntRect){left, up, right, down});
    if (!char_in_str(params->map[right][up], " flw0")) {
        params->hand_pos[0] = right;
        params->hand_pos[1] = up;
    } else if (!char_in_str(params->map[right + 1][up], " flw0")) {
        params->hand_pos[0] = right + 1;
        params->hand_pos[1] = up;
    } else {
        params->hand_pos[0] = 0;
        params->hand_pos[1] = 999;
    }
}

int point_in_rectangle(sfVector2f origin, sfVector2f size, sfVector2f pos)
{
    if (origin.x <= pos.x && pos.x <= size.x + origin.x
    && origin.y <= pos.y && pos.y <= origin.y + size.y) {
        return (1);
    }
    return (0);
}

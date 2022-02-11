/*
** EPITECH PROJECT, 2021
** keyboard event
** File description:
** keyboard
*/

#include "../include/my.h"

void keyboard_option(params_t *params)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        params->select_option = (params->select_option - 1) % 6;
        if (params->select_option < 0)
            params->select_option = 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        params->select_option = (params->select_option + 1) % 6;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        decrease_option(params);
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (params->select_option == 5) {
            volume_changer(&params->music_volume, 1, params->music_buffer);
            return;
        }
        increase_option(params);
    }
}

// My cheat for dev
void cheat_key_pressed(params_t *params)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        params->player_y = (int)(params->player_y / (int)(16 * BLOCK_SIZE)) *
        (16 * BLOCK_SIZE);
    }
    if (sfKeyboard_isKeyPressed(sfKeyB)) {
        params->start_biome++;
        if (params->start_biome == 3)
            params->start_biome = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyC)) {
        params->character = (params->character + 1) % 4;
        params->player_rect.top = 48 * params->character;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD))
        params->distance += 10;
}

void next_keyboard_event(params_t *params)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (params->fps < 120)
            params->fps += 1;
        itoa(params->fps_buffer, params->fps, 3);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        params->fps = (params->fps > 1) ? params->fps - 1 : params->fps;
        itoa(params->fps_buffer, params->fps, 3);
    }
    if (sfKeyboard_isKeyPressed(sfKeyK))
        kill_player(params);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_window(params->window);
    if (sfKeyboard_isKeyPressed(sfKeyM) && params->hand_pos[1] != 999) {
        params->score += get_block_score(params->map[params->hand_pos[0]] \
        [params->hand_pos[1]]);
        params->score = (params->score < 0) ? 0 : params->score;
        params->map[params->hand_pos[0]][params->hand_pos[1]] = ' ';
    }
    cheat_key_pressed(params);
}

void keybord_event(params_t *params)
{
    if (params->menu == 3)
        return (keyboard_option(params));
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        if (params->pause)
            params->pause = 0;
        else
            params->pause = 1;
    }
    if ((sfKeyboard_isKeyPressed(sfKeySpace)) && (params->collision[2] ||
    params->collision[3]) && !(params->collision[1] && params->collision[2] &&
    !params->collision[3])) {
        params->player_attraction = -26.3499;
        params->isjumping = 1;
    }
    next_keyboard_event(params);
}

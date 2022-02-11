/*
** EPITECH PROJECT, 2021
** option itoa
** File description:
** Custion founction for itoa
*/

#include "../include/my.h"

void itoa(char *str, int nbr, int nbr_size)
{
    nbr_size--;
    for (int count = nbr_size; count >= 0; count --) {
        str[count] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
}

int decrease_dificulty_player(params_t *params)
{
    switch (params->select_option) {
    case 3:
        params->character--;
        if (params->character == -1)
            params->character = 0;
        params->player_rect.top = 48 * params->character;
        break;
    case 1:
        params->difficulty--;
        if (params->difficulty == -1)
            params->difficulty = 2;
        break;
    case 4:
        params->track = (params->track == 0) ? 2 : params->track - 1;
        break;
    default:
        break;
    }
}

int change_volume(params_t *params)
{
    for (int count = 0; count < TOTAL_SOUND; count++)
        sfSound_setVolume(params->sound_manager->sound[count], params->sound);
    sfMusic_setVolume(params->music, params->music_volume);
}

int decrease_option(params_t *params)
{
    switch (params->select_option) {
    case 0:
        params->fps--;
        if (params->fps == 1)
            params->fps = 60;
        itoa(params->fps_buffer, params->fps, 3);
        break;
    case 2:
        params->sound--;
        if (params->sound == -1)
            params->sound = 100;
        itoa(params->sound_buffer, params->sound, 3);
        break;
    case 5:
        volume_changer(&params->music_volume, -1, params->music_buffer);
        break;
    default:
        return (decrease_dificulty_player(params));
    }
}

int increase_option(params_t *params)
{
    switch (params->select_option) {
    case 0:
        params->fps = (params->fps + 1) % 121;
        itoa(params->fps_buffer, params->fps, 3);
        break;
    case 1:
        params->difficulty = (params->difficulty + 1) % 3;
        break;
    case 2:
        volume_changer(&params->sound, 1, params->sound_buffer);
        break;
    case 3:
        params->character = (params->character + 1) % 4;
        params->player_rect.top = 48 * params->character;
        break;
    case 4:
        params->track = (params->track + 1) % 3;
        break;
    }
}

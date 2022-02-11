/*
** EPITECH PROJECT, 2021
** transition menu
** File description:
** menu
*/

#include "../include/my.h"

int transition_option(params_t *params)
{
    if (params->bg_rect.top == 0) {
        params->menu = 3;
        sfMusic_stop(params->music);
        sfMusic_destroy(params->music);
    } else {
        params->bg_rect.top = params->bg_rect.top - 40;
        sfSprite_setTextureRect(params->bg_sp, params->bg_rect);
        draw_background(params);
        sfRenderWindow_display(params->window);
    }
}

int transition_option_to_main(params_t *params)
{
    if (params->bg_rect.top == 1080) {
        params->menu = 1;
        params->music =
        sfMusic_createFromFile(params->music_list[params->track]);
        sfMusic_play(params->music);
        sfMusic_setLoop(params->music, sfTrue);
        change_volume(params);
    } else {
        params->bg_rect.top = params->bg_rect.top + 40;
        sfSprite_setTextureRect(params->bg_sp, params->bg_rect);
        draw_background(params);
        sfRenderWindow_display(params->window);
    }
}

// Display option menu
void display_label(params_t *prm)
{
    char *difficulty[3] = {"Facile", "Normal", "Difficile"};
    char *characters[] = {"Alex", "Steve", "Alex : Courrir pour elles", \
    "Ardorax"};
    char *music_name[] = {"Haggstrom", "Revenge", "Otherside"};
    char *labels[12] = {"FPS", prm->fps_buffer, "Difficulty", \
    difficulty[prm->difficulty], "SOUND", prm->sound_buffer, "character", \
    characters[prm->character], "Music", music_name[prm->track], \
    "Music Volume", prm->music_buffer};
    sfColor color[2] = {sfBlack, sfWhite};
    for (int count = 0; count < 12; count++) {
        sfText_setPosition(prm->text, (sfVector2f){400 + 50 * (count % 2), \
        150 + 60 * count});
        if (prm->select_option == count / 2 && count % 2 == 0)
            sfText_setStyle(prm->text, sfTextUnderlined);
        else
            sfText_setStyle(prm->text, sfTextRegular);
        sfText_setColor(prm->text, color[count % 2]);
        sfText_setString(prm->text, labels[count]);
        sfRenderWindow_drawText(prm->window, prm->text, NULL);
    }
}

int option(params_t *params)
{
    draw_background(params);
    display_label(params);
    sfRenderWindow_display(params->window);
}

int volume_changer(int *volume, int change, char *buffer)
{
    if (change > 0) {
        *volume = (*volume + change) % 101;
    } else {
        *volume = (*volume == 0) ? 100 : *volume - 1;
    }
    itoa(buffer, *volume, 3);
}

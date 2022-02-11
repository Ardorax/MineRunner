/*
** EPITECH PROJECT, 2021
** define
** File description:
** define other things
*/

#include "../include/my.h"

int define_menu(params_t *params)
{
    params->menu = 1;
    params->map_anim = 1;
    params->selection = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(params->selection, sfWhite);
    sfRectangleShape_setOutlineThickness(params->selection, 2.0);
    sfRectangleShape_setFillColor(params->selection, sfTransparent);
}

// Set the buffer
void define_text_const(params_t *params)
{
    itoa(params->fps_buffer, 60, 3);
    params->fps_buffer[3] = '\0';
    itoa(params->sound_buffer, 100, 3);
    itoa(params->music_buffer, 100, 3);
    params->sound_buffer[3] = '\0';
    params->score = 0;
    params->distance = 0;
    itoa(params->score_buffer, params->score, 9);
    params->score_buffer[9] = '\0';
}

int define_text(params_t *params)
{
    params->font = sfFont_createFromFile("./assets/font.ttf");
    params->text = sfText_create();
    sfText_setFont(params->text, params->font);
    sfText_setCharacterSize(params->text, 50);
    params->select_option = 0;
    define_text_const(params);
}

int define_cube(params_t *params)
{
    params->cube_sp = sfSprite_create();
    sfSprite_setTexture(params->cube_sp, params->obj_tx, sfFalse);
}

// All the music and sound manager
int define_music(params_t *params)
{
    char *sound_list[] = {"./assets/dead.ogg", "./assets/go.ogg", \
    "./assets/option.ogg", "./assets/fall.ogg", "./assets/win.ogg"};
    params->music = sfMusic_createFromFile("./assets/haggstrom.ogg");
    sfMusic_play(params->music);
    sfMusic_setLoop(params->music, sfTrue);
    params->sound_manager = malloc(sizeof(sound_sys_t));
    params->music_list[1] = "./assets/Revenge.ogg";
    params->music_list[0] = "./assets/haggstrom.ogg";
    params->music_list[2] = "./assets/music.ogg";
    params->track = 0;
    for (int count = 0; count < TOTAL_SOUND; count++) {
        params->sound_manager->buffer[count] =
        sfSoundBuffer_createFromFile(sound_list[count]);
        params->sound_manager->sound[count] = sfSound_create();
        sfSound_setBuffer(params->sound_manager->sound[count],
        params->sound_manager->buffer[count]);
    }
}

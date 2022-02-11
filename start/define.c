/*
** EPITECH PROJECT, 2021
** Define_functions
** File description:
** to create element
*/

#include "../include/my.h"

int define_background(params_t *params)
{
    params->bg_tx = sfTexture_createFromFile("./assets/bg.png", NULL);
    params->bg_sp = sfSprite_create();
    sfSprite_setTexture(params->bg_sp, params->bg_tx, sfFalse);
    params->bg_rect = (sfIntRect){0, 1080, 1920, 1080};
    params->bg_pos = (sfVector2f){0, 0};
    sfSprite_setTextureRect(params->bg_sp, params->bg_rect);
    params->bg_color = sfWhite;
}

int define_view(params_t *params)
{
    params->speed = 5;
    params->advencement = 0;
    sfVector2f view_size = {1920, 1080};
    params->view = sfView_create();
    sfView_setSize(params->view, view_size);
    sfView_setCenter(params->view, (sfVector2f){1920 / 2, 1080 / 2});
}

int define_object(params_t *params)
{
    params->player_anim = 0;
    params->player_attraction = 0;
    params->player_y = 0;
    params->player_x = 0;
    params->obj_tx = sfTexture_createFromFile("./assets/Tx2.png", NULL);
    params->obj_sp = sfSprite_create();
    params->obj_rect = (sfIntRect){0, 0, 16, 16};
    params->player_rect = (sfIntRect){0, 0, 24, 24};
    params->character = 0;
    for (int count = 0; count < 4; count++)
        params->collision[count] = 0;
    sfSprite_setTexture(params->obj_sp, params->obj_tx, sfFalse);
    params->bound_circle = sfCircleShape_create();
    sfSprite_setTextureRect(params->obj_sp, params->player_rect);
    sfSprite_setScale(params->obj_sp, (sfVector2f){BLOCK_SIZE, BLOCK_SIZE});
}

int define_const(params_t *params)
{
    int out = open("./highscore", O_RDONLY);
    for (int count = 0; count < 10; count++)
        params->best_score_buffer[count] = '0';
    params->best_score_buffer[9] = 0;
    if (out != -1) {
        read(out, params->best_score_buffer, 10);
        close(out);
    }
    params->width = 1920;
    params->height = 1080;
    sfVideoMode mode = (sfVideoMode){params->width, params->height, 32};
    params->window = sfRenderWindow_create(mode, "My Runner", \
    sfDefaultStyle, NULL);
    params->fps = 60;
    params->difficulty = 1;
    params->sound = 100;
    params->music_volume = 100;
    params->current_biome = 0;
    params->start_biome = 0;
    params->isjumping = 1;
}

int define_handler(char *map_path, int infinite)
{
    params_t *params = malloc(sizeof(params_t));
    params->map_path = map_path;
    params->infinite = infinite;
    define_const(params);
    define_view(params);
    params->map = malloc(sizeof(char *) * 30);
    sfRenderWindow_setView(params->window, params->view);
    define_background(params);
    define_object(params);
    define_cube(params);
    params->pause = 0;
    define_text(params);
    define_menu(params);
    define_music(params);
    main_loop(params);
}

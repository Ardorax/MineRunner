/*
** EPITECH PROJECT, 2021
** player death
** File description:
** player death
*/

#include "../include/my.h"

int kill_player(params_t *params)
{
    params->menu = 6;
    sfSound_play(params->sound_manager->sound[0]);
}

int block_smaller(params_t *params)
{
    draw_background(params);
    sfSprite_setScale(params->cube_sp, (sfVector2f){params->map_anim / 10.0, \
    params->map_anim / 10.0});
    draw_object(params);
    params->map_anim--;
    sfRenderWindow_display(params->window);
}

// Transition to main menu
int game_to_main(params_t *params)
{
    if (params->bg_rect.top == 1080) {
        reset_game(params);
        sfSprite_setColor(params->bg_sp, sfWhite);
        params->menu = 1;
        return (0);
    }
    if (params->map_anim != 0) {
        block_smaller(params);
    } else {
        params->bg_rect.top = params->bg_rect.top - 40;
        sfView_setRotation(params->view,
        sfView_getRotation(params->view) - 360.0 / 27.0);
        sfRenderWindow_setView(params->window, params->view);
        sfSprite_setTextureRect(params->bg_sp, params->bg_rect);
        draw_background(params);
        sfRenderWindow_display(params->window);
    }
}

int set_new_high_score(params_t *params)
{
    int out = -1;
    if (my_strcmp(hide_null(params->score_buffer), \
    hide_null(params->best_score_buffer)) > 0) {
        out = open("./highscore", O_WRONLY);
        if (out != -1) {
            write(out, params->score_buffer, 9);
            close(out);
        }
        for (int count = 0; count < 10; count++)
            params->best_score_buffer[count] = params->score_buffer[count];
    }
}

// Restart for a new game
int reset_game(params_t *params)
{
    params->bg_pos.x = 0;
    sfView_setCenter(params->view, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setRotation(params->view, 0);
    sfRenderWindow_setView(params->window, params->view);
    fclose(params->stream);
    free_map(params);
    sfSprite_setPosition(params->obj_sp, (sfVector2f){0, 0});
    params->bg_color = (sfColor){255, 255, 255, 255};
    params->player_anim = 0;
    params->player_attraction = 0;
    params->player_y = 0;
    params->player_x = 0;
    params->advencement = 0;
    set_new_high_score(params);
}

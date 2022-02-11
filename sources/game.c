/*
** EPITECH PROJECT, 2021
** game
** File description:
** update of frame
*/

#include "../include/my.h"

int update_game(params_t *params)
{
    update_map(params);
    update_player(params);
    update_background(params);
    sfView_move(params->view, (sfVector2f){(float)params->speed, 0});
    sfRenderWindow_setView(params->window, params->view);
}

int fenester_size(params_t *params)
{
    sfVector2u size = sfRenderWindow_getSize(params->window);
    if (size.x < 800)
        size.x = 800;
    if (size.y < 600)
        size.y = 600;
    sfRenderWindow_setSize(params->window, size);
}

// Draw contoller
int update_frame(params_t *params)
{
    sfRenderWindow_setFramerateLimit(params->window, params->fps);
    sfRenderWindow_clear(params->window, sfBlack);
    fenester_size(params);
    if (params->menu != 0)
        return (menu(params));
    if (params->pause == 0) {
        update_game(params);
    }
    draw_sun(params);
    draw_object(params);
    draw_player(params);
    draw_text(params);
    sfRenderWindow_display(params->window);
}

int draw_text(params_t *params)
{
    sfVector2f pos = sfView_getCenter(params->view);
    sfText_setString(params->text, "FPS:");
    sfText_setPosition(params->text, (sfVector2f){pos.x + 730, 0});
    sfRenderWindow_drawText(params->window, params->text, NULL);
    sfText_setString(params->text, hide_null(params->fps_buffer));
    sfText_setPosition(params->text, (sfVector2f){pos.x + 850, 0});
    sfRenderWindow_drawText(params->window, params->text, NULL);
    sfText_setString(params->text, hide_null(params->score_buffer));
    sfText_setPosition(params->text, (sfVector2f){pos.x + 830, 1010});
    sfRenderWindow_drawText(params->window, params->text, NULL);
    if (params->pause) {
        sfText_setString(params->text, "Press P to continue");
        sfText_setPosition(params->text, (sfVector2f){pos.x - 250, 1010});
        sfRenderWindow_drawText(params->window, params->text, NULL);
    }
}

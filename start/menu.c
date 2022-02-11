/*
** EPITECH PROJECT, 2021
** menu
** File description:
** 0:game 1: menu, 2 descend game, 3 option 4 monte option, 5desend main, 6>main
*/

#include "../include/my.h"

int draw_high_score(params_t *params)
{
    sfText_setPosition(params->text, (sfVector2f){1600, 900});
    sfText_setString(params->text, "Highscore :");
    sfRenderWindow_drawText(params->window, params->text, NULL);
    sfText_setPosition(params->text, (sfVector2f){1600, 950});
    sfText_setString(params->text, hide_null(params->best_score_buffer));
    sfRenderWindow_drawText(params->window, params->text, NULL);
}

int draw_menu_action(params_t *params)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(params->window);
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(params->window, mouse,
    params->view);
    sfVector2f play_origin = {640, 730};
    sfVector2f play_size = {160, 80};
    sfVector2f option_origin = {980, 730};
    sfVector2f option_size = {290, 80};
    sfRectangleShape_setPosition(params->selection, (sfVector2f){0, 0});
    if (point_in_rectangle(play_origin, play_size, coords)) {
        sfRectangleShape_setPosition(params->selection, play_origin);
        sfRectangleShape_setSize(params->selection, play_size);
        sfRenderWindow_drawRectangleShape(params->window,
        params->selection, NULL);
    } else if (point_in_rectangle(option_origin, option_size, coords)) {
        sfRectangleShape_setPosition(params->selection, option_origin);
        sfRectangleShape_setSize(params->selection, option_size);
        sfRenderWindow_drawRectangleShape(params->window,
        params->selection, NULL);
    }
    draw_high_score(params);
}

// Make block appear
int block_bigger(params_t *params)
{
    if (params->map_anim == 51) {
        params->menu = 0;
    }
    draw_background(params);
    sfSprite_setScale(params->cube_sp, (sfVector2f){params->map_anim / 10.0, \
    params->map_anim / 10.0});
    draw_object(params);
    params->map_anim++;
    draw_text(params);
    sfRenderWindow_display(params->window);
}

// Transition to game
int transition_down(params_t *params)
{
    if (params->bg_rect.top == 1080) {
        params->pause = 0;
        load_map(params);
        params->score = 0;
        params->distance = 0;
        params->start_biome = 0;
    }
    if (params->bg_rect.top == 2160) {
        block_bigger(params);
    } else {
        params->bg_rect.top = params->bg_rect.top + 40;
        sfSprite_setTextureRect(params->bg_sp, params->bg_rect);
        draw_background(params);
        sfRenderWindow_display(params->window);
    }
}

// Function to control all the menu
int menu(params_t *params)
{
    switch (params->menu) {
    case 2:
        return (transition_down(params));
    case 4:
        return (transition_option(params));
    case 3:
        return (option(params));
    case 5:
        return (transition_option_to_main(params));
    case 6:
        return (game_to_main(params));
    default:
        draw_background(params);
        draw_menu_action(params);
        sfRenderWindow_display(params->window);
        break;
    }
}

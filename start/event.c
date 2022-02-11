/*
** EPITECH PROJECT, 2021
** event
** File description:
** event handler
*/

#include "../include/my.h"
#include "math.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void option_event(params_t *params)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(params->window,
    sfMouse_getPositionRenderWindow(params->window), params->view);
    if (params->event.mouseButton.button == sfMouseLeft && coords.y > 960) {
        sfSound_play(params->sound_manager->sound[2]);
        params->menu = 5;
    }
}

// Play and option button
void main_menu_selector(params_t *params)
{
    if (sfRectangleShape_getPosition(params->selection).x == 640) {
        sfSound_play(params->sound_manager->sound[1]);
        params->menu = 2;
    } else if (sfRectangleShape_getPosition(params->selection).x == 980) {
        sfSound_play(params->sound_manager->sound[2]);
        params->menu = 4;
    }
}

void mouse_event(params_t *params)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(params->window);
    sfVector2f clear = sfRenderWindow_mapPixelToCoords(params->window,
    pos, params->view);
    clear.x -= sfView_getCenter(params->view).x - 960;
    clear.y -= sfView_getCenter(params->view).y - 540;
    if (params->event.mouseButton.button == sfMouseLeft && clear.x <= 80.0 &&
    clear.y <= 80.0) {
        return (close_window(params->window));
    }
    if (params->menu == 3)
        return (option_event(params));
    if (params->event.mouseButton.button == sfMouseLeft && params->menu == 1)
        return (main_menu_selector(params));
}

int analyse_events(params_t *params)
{
    if (params->event.type == sfEvtClosed) {
        close_window(params->window);
    }
    if (params->event.type == sfEvtKeyPressed)
        keybord_event(params);
    if (params->event.type == sfEvtMouseButtonPressed)
        mouse_event(params);
}

/*
** EPITECH PROJECT, 2021
** main loop
** File description:
** each time i do ...
*/

#include "../include/my.h"

// The only clock of the program
int main_loop(params_t *params)
{
    float seconds;
    sfTime time;
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(params->window)) {
        while (sfRenderWindow_pollEvent(params->window, &params->event)) {
            analyse_events(params);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds >= 1 / 60.0) {
            update_frame(params);
            sfClock_restart(clock);
        }
    }
    sfClock_destroy(clock);
    end_destroy(params);
}

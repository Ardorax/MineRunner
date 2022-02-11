/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function of the project
*/

#include "../include/my.h"

int free_map(params_t *params)
{
    for (int count = 0; count < 25; count++)
        free(params->map[count]);
}

int free_sound_manager(sound_sys_t *sound_manager)
{
    for (int count = 0; count < TOTAL_SOUND; count++) {
        sfSoundBuffer_destroy(sound_manager->buffer[count]);
        sfSound_destroy(sound_manager->sound[count]);
    }
}

// End of program
int end_destroy(params_t *params)
{
    sfSprite_destroy(params->bg_sp);
    sfTexture_destroy(params->bg_tx);
    sfSprite_destroy(params->obj_sp);
    sfTexture_destroy(params->obj_tx);
    sfSprite_destroy(params->cube_sp);
    sfView_destroy(params->view);
    sfRectangleShape_destroy(params->selection);
    if (params->menu != 3) {
        sfMusic_stop(params->music);
        sfMusic_destroy(params->music);
    }
    sfFont_destroy(params->font);
    sfText_destroy(params->text);
    sfCircleShape_destroy(params->bound_circle);
    sfRenderWindow_destroy(params->window);
    free_sound_manager(params->sound_manager);
    free(params->map);
    free(params);
}

// -h arg
int print_usage(void)
{
    write(1, "Welcome to MineRunner\n\nGo to the option or play by "
    "clicking with your mouse.\nIn the option menu you can move with "
    "the key arrow on your keyboard. Choose your settings !\nWhen you"
    " play, you can use the spacebar to jump and the key M to mine "
    "block. Beware some of them can make you lose points... "
    "or win some ?!\nWrite a map file as second arguments and -i"
    " as third if you want an infinite play !\n\nEnjoy !\n", 402);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        write(2, "Please, use -h to see help or put a map as argument\n", 52);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        return (print_usage());
    }
    int out = open(av[1], O_RDONLY);
    if (out == -1) {
        write(1, "Error in map\n", 14);
        return (84);
    }
    close(out);
    return (start(ac, av));
}

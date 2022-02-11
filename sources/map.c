/*
** EPITECH PROJECT, 2021
** map
** File description:
** handle map
*/

#include "../include/my.h"

int move_map(params_t *params, char *new_str)
{
    free(params->map[0]);
    for (int column = 1; column < 30; column++) {
        params->map[column - 1] = params->map[column];
    }
    if (params->map[0][0] >= '!' && params->map[0][0] <= '$')
        params->start_biome = params->map[0][0] - '!';
    params->map[29] = new_str;
}

int load_map(params_t *params)
{
    params->stream = fopen(params->map_path, "r");
    if (params->stream == NULL)
        return (84);
    char *line = NULL;
    size_t size = 0;
    char *new_str = NULL;
    for (int count = 0; count < 30; count++) {
        getline(&line, &size, params->stream);
        new_str = malloc(sizeof(char) * (my_strlen(line) + 1));
        params->map[count] = my_strcpy(new_str, line);
    }
}

int load_random_map(params_t *params)
{
    char *maps[] = {"./maps/noname", "./maps/follow"};
    char *line = NULL;
    size_t size = 0;
    int choice = 0;
    srand(params->distance);
    choice = rand() % 2;
    fclose(params->stream);
    params->stream = fopen(maps[choice], "r");
    if (params->stream == NULL)
        params->menu = 6;
    getline(&line, &size, params->stream);
    move_map(params, give_malloc_str(line));
    return (0);
}

// change map file if infinite mod
int change_map(params_t *params)
{
    char *line = NULL;
    size_t size = 0;
    if (!params->infinite && params->current_biome == 3) {
        sfSound_play(params->sound_manager->sound[4]);
        params->menu = 6;
        return (0);
    }
    if (params->infinite == 0) {
        fclose(params->stream);
        params->stream = fopen("./maps/end", "r");
        if (params->stream == NULL)
            params->menu = 6;
        getline(&line, &size, params->stream);
        move_map(params, give_malloc_str(line));
        return (0);
    }
    if (params->infinite)
        return (load_random_map(params));
}

int update_map(params_t *params)
{
    params->advencement = params->advencement + params->speed;
    char *line = NULL;
    size_t size = 0;
    int out;
    while (params->advencement >= 16 * BLOCK_SIZE) {
        params->advencement -= 16 * BLOCK_SIZE;
        out = getline(&line, &size, params->stream);
        if (out != -1)
            move_map(params, give_malloc_str(line));
        else
            change_map(params);
        params->score++;
        params->distance++;
        itoa(params->score_buffer, params->score, 9);
        create_obstacle(params);
    }
}

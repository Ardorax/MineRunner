/*
** EPITECH PROJECT, 2021
** Draw background
** File description:
** draw and calcul background
*/

#include "../include/my.h"
#include "math.h"

int background_color(params_t *params, float angle)
{
    if (angle > 0 && params->bg_color.r < 255) {
        params->bg_color.r += 2;
        params->bg_color.g += 2;
        params->bg_color.b += 2;
        sfSprite_setColor(params->bg_sp, params->bg_color);
    } else if (angle < 0 && params->bg_color.r > 25) {
        params->bg_color.r -= 2;
        params->bg_color.g -= 2;
        params->bg_color.b -= 2;
        sfSprite_setColor(params->bg_sp, params->bg_color);
    }
}

int draw_sun(params_t *params)
{
    sfIntRect sun_rect = {0, 448, 32, 32};
    sfVector2f pos = sfView_getCenter(params->view);
    sfVector2f angle;
    angle.x = cosf(((params->distance % 360) + (params->advencement /
    (float)(16 * BLOCK_SIZE))) * 0.0174533) * 900.0;
    angle.y = sinf(((params->distance % 360) + (params->advencement /
    (float)(16 * BLOCK_SIZE))) * 0.0174533) * 900.0;
    background_color(params, angle.y);
    draw_background(params);
    sfSprite_setTextureRect(params->cube_sp, sun_rect);
    sfSprite_setPosition(params->cube_sp, (sfVector2f){pos.x - angle.x - 16.0, \
    pos.y - angle.y - 16.0 + 300});
    sfRenderWindow_drawSprite(params->window, params->cube_sp, NULL);
    sun_rect.left = sun_rect.left + 32;
    sfSprite_setTextureRect(params->cube_sp, sun_rect);
    sfSprite_setPosition(params->cube_sp, (sfVector2f){pos.x + angle.x - 16.0, \
    pos.y + angle.y - 16.0 + 300});
    sfRenderWindow_drawSprite(params->window, params->cube_sp, NULL);
}

int draw_background(params_t *params)
{
    sfVector2f pos = params->bg_pos;
    sfSprite_setPosition(params->bg_sp, params->bg_pos);
    sfRenderWindow_drawSprite(params->window, params->bg_sp, NULL);
    sfSprite_setPosition(params->bg_sp, (sfVector2f){params->bg_pos.x + 1920, \
    params->bg_pos.y});
    sfRenderWindow_drawSprite(params->window, params->bg_sp, NULL);
    sfSprite_setTextureRect(params->cube_sp, (sfIntRect){64, 464, 16, 16});
    sfVector2f up_left = sfView_getCenter(params->view);
    up_left.x -= 1920 / 2;
    up_left.y -= 540;
    sfSprite_setPosition(params->cube_sp, up_left);
    sfSprite_setScale(params->cube_sp, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(params->window, params->cube_sp, NULL);
}

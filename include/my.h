/*
** EPITECH PROJECT, 2021
** my h
** File description:
** my h
*/

#ifndef MY_H
    #define MY_H
    #define BLOCK_SIZE 5
    #define TOTAL_SOUND 5
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct sound_sys {
    sfSoundBuffer *buffer[TOTAL_SOUND];
    sfSound *sound[TOTAL_SOUND];
} sound_sys_t;

typedef struct params {
    int height;
    int width;
    int player_anim;
    int speed;
    int advencement;
    int pause;
    int menu;
    int map_anim;
    int select_option;
    int fps;
    char fps_buffer[4];
    int difficulty;
    int sound;
    char sound_buffer[4];
    int music_volume;
    char music_buffer[4];
    int score;
    int distance;
    char score_buffer[10];
    char best_score_buffer[10];
    char *map_path;
    int start_biome;
    int current_biome;
    int infinite;
    int isjumping;
    int character;
    sfRenderWindow *window;
    sfEvent event;
    sfRectangleShape *selection;
    sfFont *font;
    sfText *text;
    sfTexture *bg_tx;
    sfSprite *bg_sp;
    sfIntRect bg_rect;
    sfColor bg_color;
    sfTexture *obj_tx;
    sfSprite *obj_sp;
    sfIntRect player_rect;
    float player_y;
    float player_x;
    float player_attraction;
    sfCircleShape *bound_circle;
    int collision[4];
    int hand_pos[2];
    sfVector2f upleft;
    sfVector2f downright;
    sfIntRect obj_rect;
    sfView *view;
    sfVector2f bg_pos;
    sfSprite *cube_sp;
    char *music_list[3];
    int track;
    sfMusic *music;
    char **map;
    FILE *stream;
    sound_sys_t *sound_manager;
} params_t;

//autocomplete:start
// ./lib/my/delete_null.c
// delete null
char *hide_null(char *str);

// ./lib/my/find_char_in_str.c
// find_char_is_str
int char_in_str(char c, char *str);

// ./lib/my/give_malloc_str.c
// give malloc str
char *give_malloc_str(char *str);

// ./lib/my/my_put_str.c
// my put str
void my_put_str(char *str, int count);

// ./lib/my/my_putchar.c
// my putchar
void my_putchar(char c);

// ./lib/my/my_strcmp.c
// My strcmp
int my_strcmp(char const *s1, char const *s2);

// ./lib/my/my_strcpy.c
// My strcpy
char *my_strcpy(char *dest, char const *src);

// ./lib/my/my_strlen.c
// My putstr
int my_strlen(char const *str);

// ./obstacles/create_obstacles.c
// create obstacles
int put_block(params_t *params, int x, int y, char block);
int create_obstacle(params_t *params);

// ./obstacles/put_tree.c
// put tree
int create_oak(params_t *params, int y_pos);
int create_spruce(params_t *params, int y_pos);
int create_cactus(params_t *params, int y_pos);
int create_tree(params_t *params, int y_pos);

// ./sources/collision.c
// collision
int kill_player_collision(params_t *params, sfIntRect corner);
int set_collision(params_t *params, sfIntRect corner);
int corner_collide(params_t *params);
int point_in_rectangle(sfVector2f origin, sfVector2f size, sfVector2f pos);

// ./sources/draw.c
// draw
int draw_in_map(params_t *params, sfVector2f pos, int col, int line);
int draw_object(params_t *params);
int draw_player(params_t *params);

// ./sources/draw_background.c
// Draw background
int background_color(params_t *params, float angle);
int draw_sun(params_t *params);
int draw_background(params_t *params);

// ./sources/game.c
// game
int update_game(params_t *params);
int fenester_size(params_t *params);
int update_frame(params_t *params);
int draw_text(params_t *params);

// ./sources/get_block.c
// get block
int alternate(int anim);
sfIntRect get_anim_block(char b, int anim);
sfIntRect get_block(char b, int anim, int biome);
int get_block_score(char b);

// ./sources/map.c
// map
int move_map(params_t *params, char *new_str);
int load_map(params_t *params);
int load_random_map(params_t *params);
int change_map(params_t *params);
int update_map(params_t *params);

// ./sources/player.c
// player
int update_anim(params_t *params);
int draw_bound(params_t *params);
int set_bound(params_t *params);

// ./sources/player_collide.c
// player collide
int reset_y(params_t *params);
int cancel_jump_ground(params_t *params);
void end_of_ride(params_t *params);
int floor_wall_collide(params_t *params);
int main_collide(params_t *params);

// ./sources/update.c
// update
int update_background(params_t *params);
int update_player(params_t *params);

// ./start/define.c
// Define_functions
int define_background(params_t *params);
int define_view(params_t *params);
int define_object(params_t *params);
int define_const(params_t *params);
int define_handler(char *map_path, int infinite);

// ./start/define_side.c
// define
int define_menu(params_t *params);
void define_text_const(params_t *params);
int define_text(params_t *params);
int define_cube(params_t *params);
int define_music(params_t *params);

// ./start/event.c
// event
void close_window(sfRenderWindow *window);
void option_event(params_t *params);
void main_menu_selector(params_t *params);
void mouse_event(params_t *params);
int analyse_events(params_t *params);

// ./start/keyboard_event.c
// keyboard event
void keyboard_option(params_t *params);
void cheat_key_pressed(params_t *params);
void next_keyboard_event(params_t *params);
void keybord_event(params_t *params);

// ./start/main.c
// main
int free_map(params_t *params);
int free_sound_manager(sound_sys_t *sound_manager);
int end_destroy(params_t *params);
int print_usage(void);
int main(int ac, char **av);

// ./start/main_loop.c
// main loop
int main_loop(params_t *params);

// ./start/menu.c
// menu
int draw_high_score(params_t *params);
int draw_menu_action(params_t *params);
int block_bigger(params_t *params);
int transition_down(params_t *params);
int menu(params_t *params);

// ./start/option.c
// transition menu
int transition_option(params_t *params);
int transition_option_to_main(params_t *params);
void display_label(params_t *prm);
int option(params_t *params);
int volume_changer(int *volume, int change, char *buffer);

// ./start/option_itoa.c
// option itoa
void itoa(char *str, int nbr, int nbr_size);
int decrease_dificulty_player(params_t *params);
int change_volume(params_t *params);
int decrease_option(params_t *params);
int increase_option(params_t *params);

// ./start/player_death.c
// player death
int kill_player(params_t *params);
int block_smaller(params_t *params);
int game_to_main(params_t *params);
int set_new_high_score(params_t *params);
int reset_game(params_t *params);

// ./start/start.c
// start game
int start(int ac, char **av);
//autocomplete:end

#endif /* !MY_H */

/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** my runner prototypes
*/

#ifndef _MY_HUNTER
#define _MY_HUNTER

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct sprite_s
{
    sfSprite* bg;
    sfTexture *bg_text;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *runner_text;
    sfIntRect runner_rect;
    sfSprite *runner;
    sfVector2f pos_runner;
    sfSprite **tab;
    int size;
    sfClock *clock_move2;
    sfClock *clock_move3;
    sfTime time;
    float seconds;
    sfVector2f velocity;
    int count;
    int jump_state;
    int hit;
    char *choice;
    int speed;
    int score;
    int i;
    sfSprite *bloc_max;
    sfVector2f pos_max;
    sfSprite *win;
    sfVector2f pos_win;
    sfSprite *end;
    sfVector2f pos_end;
    sfText *text;
    sfText *text_score;
    sfVector2f pos_text;
    sfSoundBuffer *soundbuffer;
    sfSoundBuffer *soundbuffer2;
    sfSound *sound;
    sfSound *music;
}sprite_t;

typedef struct menu_s
{
    int disp_menu;
    int quit_menu;
    sfSprite* play;
    sfVector2f pos_play;
    sfVector2f pos_quit;
    sfFloatRect b_play;
    sfFloatRect b_quit;
    sfFloatRect b_resume;
    sfSprite* bg_menu;
    sfSprite* quit;
    sfVector2f pos_bg;
    sfSprite *resume;
    sfTexture *resume_text;
    sfIntRect resume_rect;
    sfVector2f pos_resume;
    int pause;
    int disp_pause;

}menu_t;

typedef struct parallax_s
{
    sfTime time;
    float seconds;
    sfClock *clock_move;
    sfIntRect rect;
    sfTexture *texture[3];
    sfSprite *para_sprite[3];
    sfVector2f pos_para;
    int x[3];
}parallax_t;

/* LIB */
int my_strcmp(char const *s1, char const *s2);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *int_to_str(int nb);
/* SPRITE */
sfSprite *create_sprite(sfTexture *texture);
void destroy_elements(sprite_t *sprite, parallax_t *parallax, menu_t *menu);
void move_runner(sprite_t *sprite);
sfVector2f init_pos(float x, float y);
void init_runner(sprite_t *sprite);
void set_bloc1(sprite_t *sprite, int x);
void set_bloc2(sprite_t *sprite, int x);
void set_mummy(sprite_t *sprite);
void move_runner2(sprite_t *sprite);
char *entry_choice(void);
/* MENU */
void set_name(sprite_t *sprite);
void set_play(menu_t *menu, sprite_t *sprite);
void set_quit(menu_t *menu, sprite_t *sprite);
void display_menu(sprite_t *sprite, menu_t *menu);
void init_menu(menu_t *menu, sprite_t *sprite);
void set_buttons_elements(sprite_t *sprite, menu_t *menu);
/* PARALLAX */
void set_parallax(sprite_t *sprite, parallax_t *parallax);
void move_bg(sprite_t *sprite, parallax_t *parallax);
/* HANDLE MAP */
void spawn_obstacles(char *buffer, sprite_t *sprite);
void move_bloc(sfSprite *sprite);
char *entry_map(char *map);
/* WIN OR LOSE */
int check_collision(sfSprite *runner, sfSprite *obstacle, sprite_t *sprite);
void game_over(sprite_t *sprite);
void win_or_lose(sprite_t *sprite);
/* PAUSE */
void display_pause(menu_t *menu, sprite_t *sprite);
void set_resume(menu_t *menu, sprite_t *sprite);
/* JUMP */
void set_jump_sound(sprite_t *sprite);
void handle_jump(sprite_t *sprite);
/* SET ELEMENTS FUNCTIONS */
void set_score(sprite_t *sprite);
void set_name(sprite_t *sprite);
void set_music(sprite_t *sprite);
void destroy_elements(sprite_t *sprite, parallax_t *parallax, menu_t *menu);
void init_and_set_elements(sprite_t *sprite, menu_t *menu);
void clock_create(sprite_t *sprite, parallax_t *parallax);
void print_help(void);

#endif /* !_MY_HUNTER */

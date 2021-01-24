/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** init_and destroy_elements
*/

#include "../includes/my_runner.h"

void init_and_set_elements(sprite_t *sprite, menu_t *menu)
{
    sprite->score = 0;
    sprite->count = 0;
    sprite->hit = 0;
    sprite->speed = 0;
    menu->pause = 0;
    set_jump_sound(sprite);
    set_music(sprite);
    sfSound_play(sprite->music);
}

void destroy_elements(sprite_t *sprite, parallax_t *parallax, menu_t *menu)
{
    sfRenderWindow_destroy(sprite->window);
    sfSprite_destroy(sprite->bg);
    sfSprite_destroy(sprite->runner);
    sfText_destroy(sprite->text);
    sfText_destroy(sprite->text_score);
    sfSound_destroy(sprite->music);
    sfSound_destroy(sprite->sound);
    sfSoundBuffer_destroy(sprite->soundbuffer);
    sfSoundBuffer_destroy(sprite->soundbuffer2);
    if (menu->pause == 1)
        sfSprite_destroy(menu->resume);
    sfSprite_destroy(menu->play);
    if (sprite->hit == 1)
        sfSprite_destroy(sprite->end);
    else if (sprite->hit == 0)
        sfSprite_destroy(sprite->win);
    sfSprite_destroy(menu->quit);
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_runner map for play\n");
    my_putstr("\t./my_runner -h for help\n");
    my_putstr("USE MAP\n");
    my_putstr("Enter 1, 2 or 3 for place obstacles in file give as argument\n");
    my_putstr("Enter space for nothing\n");
    my_putstr("if you enter anything else, nothing will display\n");
    my_putchar('\n');
    my_putstr("USER INTERACTIONS\n");
    my_putchar('\n');
    my_putstr("PRESSED 1 OR 2\tchoose characters.");
    my_putstr("MOUSE CLIC LEFT ON SCREEN\tplay, quit, resume.\n");
    my_putstr("SPACE_KEY\tjump.\n");
    my_putstr("ESCAPE\tpause.\n");
}

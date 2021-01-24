/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** set_sprite_buttons
*/

#include "../includes/my_runner.h"

void set_play(menu_t *menu, sprite_t *sprite)
{
    menu->disp_menu = 1;
    menu->play = create_sprite(sfTexture_createFromFile("assets/play.png",
    NULL));
    menu->pos_play.x = sfRenderWindow_getSize(sprite->window).x/2 - 111;
    menu->pos_play.y = sfRenderWindow_getSize(sprite->window).y/2 - 48;
    sfSprite_setPosition(menu->play, menu->pos_play);
}

void set_quit(menu_t *menu, sprite_t *sprite)
{
    menu->quit = create_sprite(sfTexture_createFromFile("assets/quit.png",
    NULL));
    menu->pos_quit.x = sfRenderWindow_getSize(sprite->window).x/2 - 111;
    menu->pos_quit.y = sfRenderWindow_getSize(sprite->window).y/2 + 58;
    sfSprite_setPosition(menu->quit, menu->pos_quit);
}

void set_resume(menu_t *menu, sprite_t *sprite)
{
    menu->disp_pause = 1;
    menu->resume = create_sprite(sfTexture_createFromFile("assets/resume.png",
    NULL));
    menu->pos_resume.x = sfRenderWindow_getSize(sprite->window).x/2 - 50;
    menu->pos_resume.y = sfRenderWindow_getSize(sprite->window).y/2 - 100;
    sfSprite_setPosition(menu->resume, menu->pos_resume);
}
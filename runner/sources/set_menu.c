/*
** EPITECH PROJECT, 2020
** set_menu
** File description:
** set_menu for my_runner game
*/

#include "../includes/my_runner.h"

void init_menu(menu_t *menu, sprite_t *sprite)
{
    sprite->bg = sfSprite_create();
    sprite->bg_text = sfTexture_createFromFile("assets/bg2.png", NULL);
    sfSprite_setTexture(sprite->bg, sprite->bg_text, sfTrue);
    sfSprite_setScale(sprite->bg,
        init_pos((float)sfRenderWindow_getSize(sprite->window).x /
        sfTexture_getSize(sprite->bg_text).x,
        (float)sfRenderWindow_getSize(sprite->window).y /
        sfTexture_getSize(sprite->bg_text).y));
}

void set_menu_elements(sprite_t *sprite, menu_t *menu)
{
    set_play(menu, sprite);
    set_quit(menu, sprite);
    set_name(sprite);
}

void draw_menu_sprite(sprite_t *sprite, menu_t *menu)
{
    sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
    sfRenderWindow_drawSprite(sprite->window, menu->play, NULL);
    sfRenderWindow_drawSprite(sprite->window, menu->quit, NULL);
    sfRenderWindow_drawText(sprite->window, sprite->text, NULL);
}

void display_menu(sprite_t *sprite, menu_t *menu)
{
    set_menu_elements(sprite, menu);
    while (sfRenderWindow_isOpen(sprite->window) && menu->disp_menu) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        draw_menu_sprite(sprite, menu);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
            if (sprite->event.type == sfEvtClosed)
                sfRenderWindow_close(sprite->window);
            menu->b_quit = sfSprite_getGlobalBounds(menu->quit);
            if (sprite->event.type == sfEvtMouseButtonPressed
                && sfFloatRect_contains(&menu->b_quit,
                sprite->event.mouseButton.x, sprite->event.mouseButton.y))
                sfRenderWindow_close(sprite->window);
            menu->b_play = sfSprite_getGlobalBounds(menu->play);
            if (sprite->event.type == sfEvtMouseButtonPressed
                && sfFloatRect_contains(&menu->b_play,
                sprite->event.mouseButton.x, sprite->event.mouseButton.y))
                menu->disp_menu = 0;
        }
        sfRenderWindow_display(sprite->window);
    }
}

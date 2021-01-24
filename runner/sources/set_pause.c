/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** set_pause
*/

#include "../includes/my_runner.h"

void set_pause_elements(sprite_t *sprite, menu_t *menu)
{
    set_resume(menu, sprite);
    set_quit(menu, sprite);
    set_name(sprite);
}

void draw_pause_sprite(sprite_t *sprite, menu_t *menu)
{
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
    sfRenderWindow_drawSprite(sprite->window, menu->resume, NULL);
    sfRenderWindow_drawSprite(sprite->window, menu->quit, NULL);
    sfRenderWindow_drawText(sprite->window, sprite->text, NULL);
    sfSound_pause(sprite->music);
}

void cond_resume(sprite_t *sprite, menu_t *menu)
{
    if (sprite->event.type == sfEvtMouseButtonPressed
        && sfFloatRect_contains(&menu->b_resume,
        sprite->event.mouseButton.x, sprite->event.mouseButton.y)) {
        menu->disp_pause = 0;
        sfSound_play(sprite->music);
    }
}

void display_pause(menu_t *menu, sprite_t *sprite)
{
    set_pause_elements(sprite, menu);
    while (sfRenderWindow_isOpen(sprite->window) && menu->disp_pause) {
        draw_pause_sprite(sprite, menu);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
            if (sprite->event.type == sfEvtClosed)
                sfRenderWindow_close(sprite->window);
            menu->b_quit = sfSprite_getGlobalBounds(menu->quit);
            if (sprite->event.type == sfEvtMouseButtonPressed
                && sfFloatRect_contains(&menu->b_quit,
                sprite->event.mouseButton.x, sprite->event.mouseButton.y))
                sfRenderWindow_close(sprite->window);
            menu->b_resume = sfSprite_getGlobalBounds(menu->resume);
            cond_resume(sprite, menu);
        }
        sfRenderWindow_display(sprite->window);
    }
}
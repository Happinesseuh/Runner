/*
** EPITECH PROJECT, 2021
** collisions.c
** File description:
** collisions
*/

#include "../includes/my_runner.h"

int check_collision(sfSprite *runner, sfSprite *obstacle, sprite_t *sprite)
{
    sfFloatRect runner_rect = sfSprite_getGlobalBounds(runner);
    sfFloatRect obstacle_rect = sfSprite_getGlobalBounds(obstacle);
    if (sfFloatRect_intersects(&runner_rect,
        &obstacle_rect, NULL) == sfTrue)
        return 1;
    return 0;
}

void game_over(sprite_t *sprite)
{
    sprite->end = create_sprite(sfTexture_createFromFile("assets/end.png",
    NULL));
    sprite->pos_end.x = sfRenderWindow_getSize(sprite->window).x/2 - 150;
    sprite->pos_end.y = sfRenderWindow_getSize(sprite->window).y/2 - 100;
    sfSprite_setPosition(sprite->end, sprite->pos_end);
    sfSound_stop(sprite->music);
    while (sfRenderWindow_isOpen(sprite->window) && sprite->hit == 1) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
        sfRenderWindow_drawSprite(sprite->window, sprite->end, NULL);
        set_score(sprite);
        sfRenderWindow_drawText(sprite->window, sprite->text, NULL);
        sfRenderWindow_drawText(sprite->window, sprite->text_score, NULL);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
        if (sprite->event.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
        }
        sfRenderWindow_display(sprite->window);
    }
}

void game_win(sprite_t *sprite)
{
    sprite->win = create_sprite(sfTexture_createFromFile("assets/win.png",
    NULL));
    sprite->pos_win.x = sfRenderWindow_getSize(sprite->window).x/2 - 300;
    sprite->pos_win.y = sfRenderWindow_getSize(sprite->window).y/2 - 300;
    sfSprite_setPosition(sprite->win, sprite->pos_win);
    sfSprite_setScale(sprite->win, init_pos(0.7, 0.7));
    sfSound_stop(sprite->music);
    while (sfRenderWindow_isOpen(sprite->window) && sprite->hit == 0) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
        sfRenderWindow_drawSprite(sprite->window, sprite->win, NULL);
        set_score(sprite);
        sfRenderWindow_drawText(sprite->window, sprite->text, NULL);
        sfRenderWindow_drawText(sprite->window, sprite->text_score, NULL);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
        if (sprite->event.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
        }
        sfRenderWindow_display(sprite->window);
    }
}

void win_or_lose(sprite_t *sprite)
{
    if (sprite->pos_max.x < 0 && sprite->hit == 0)
        game_win(sprite);
    if (sprite->hit == 1)
        game_over(sprite);
}
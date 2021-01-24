/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** parallax
*/

#include "../includes/my_runner.h"

sfVector2f init_pos(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

void set_pos_parallax(parallax_t *parallax, sprite_t *sprite)
{
    parallax->rect.left = 0;
    parallax->rect.top = 0;
    parallax->rect.height = sfRenderWindow_getSize(sprite->window).x;
    parallax->rect.width = sfRenderWindow_getSize(sprite->window).y;
}

void set_parallax(sprite_t *sprite, parallax_t *parallax)
{
    char *image[3] = {"assets/0.png", "assets/1.png", "assets/2.png"};

    set_pos_parallax(parallax, sprite);
    for (int i = 0; i < 3; i++) {
        parallax->texture[i] = sfTexture_createFromFile(image[i], NULL);
        parallax->para_sprite[i] = sfSprite_create();
        sfTexture_setRepeated(parallax->texture[i], sfTrue);
        sfSprite_setTexture(parallax->para_sprite[i],
            parallax->texture[i], sfTrue);
        sfSprite_setScale(parallax->para_sprite[i],
        init_pos((float)sfRenderWindow_getSize(sprite->window).x /
        sfTexture_getSize(parallax->texture[i]).x, (float)sfRenderWindow_getSize
        (sprite->window).y/ sfTexture_getSize(parallax->texture[i]).y));
        sfSprite_setTextureRect(parallax->para_sprite[i], parallax->rect);
        parallax->x[i] = 0;
    }
    parallax->clock_move = sfClock_create();
}

void move_bg(sprite_t *sprite, parallax_t *parallax)
{
    for (int i = 0; i < 3; i++) {
        if (parallax->x[i] <= -(int)sfRenderWindow_getSize(sprite->window).x)
            parallax->x[i] = -2;
        else
            parallax->x[i] -= (4 + i);
        sfSprite_setPosition(parallax->para_sprite[i],
            init_pos(parallax->x[i], 0));
    }
}
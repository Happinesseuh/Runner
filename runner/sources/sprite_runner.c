/*
** EPITECH PROJECT, 2020
** sprite.c
** File description:
** sprite
*/

#include "../includes/my_runner.h"

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void move_runner(sprite_t *sprite)
{
    if (sprite->runner_rect.left < 680) {
        sprite->time = sfClock_getElapsedTime(sprite->clock_move2);
        sprite->seconds = sprite->time.microseconds / 1000000.0;
        if (sprite->seconds > 0.10) {
            sprite->runner_rect.left += 136;
            if (sprite->runner_rect.left >= 680)
                sprite->runner_rect.left = 0;
            sfSprite_setTextureRect(sprite->runner, sprite->runner_rect);
            sfClock_restart(sprite->clock_move2);
        }
    }
}

char *entry_choice(void)
{
    char *buffer;
    size_t buffsize = 2;
    size_t entry;

    buffer = (char *)malloc(buffsize * sizeof(char));
    my_putstr("1- beige\n");
    my_putstr("2- blue\n");
    my_putstr("3- yellow\n");
    my_putstr("4- pink\n");
    my_putstr("Choose your character : ");
    entry = getline(&buffer, &buffsize, stdin);
    return (buffer);
}

void custom_character(sprite_t *sprite)
{
    if (sprite->choice[0] == '1')
        sprite->runner_text = sfTexture_createFromFile("./assets/perso.png"
        , NULL);
    if (sprite->choice[0] == '2')
        sprite->runner_text = sfTexture_createFromFile("./assets/perso2.png"
        , NULL);
    if (sprite->choice[0] == '3')
        sprite->runner_text = sfTexture_createFromFile("./assets/perso3.png"
        , NULL);
    if (sprite->choice[0] == '4')
        sprite->runner_text = sfTexture_createFromFile("./assets/perso4.png"
        , NULL);
}

void init_runner(sprite_t *sprite)
{
    sprite->runner_rect.top = 0;
    sprite->runner_rect.left = 0;
    sprite->runner_rect.width = 136;
    sprite->runner_rect.height = 145;
    sprite->runner = sfSprite_create();
    custom_character(sprite);
    sfSprite_setTexture(sprite->runner, sprite->runner_text, sfTrue);
    sfSprite_setTextureRect(sprite->runner, sprite->runner_rect);
    sprite->pos_runner.x = 300;
    sprite->pos_runner.y = 700;
    sfSprite_setPosition(sprite->runner, sprite->pos_runner);
}

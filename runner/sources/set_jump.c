/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** set_jump
*/

#include "../includes/my_runner.h"

void set_jump_sound(sprite_t *sprite)
{
    sprite->soundbuffer = sfSoundBuffer_createFromFile("./assets/sound.wav");
    sprite->sound = sfSound_create();
    sfSound_setBuffer(sprite->sound, sprite->soundbuffer);
}

void handle_jump(sprite_t *sprite)
{
    sprite->velocity = init_pos(5, 10);

    if (sprite->count == 1) {
        if (sprite->pos_runner.y <= 440)
            sprite->jump_state = 0;
        sprite->runner_rect.left = 136;
        if (sprite->jump_state == 1) {
            sprite->pos_runner.y -= sprite->velocity.y;
            sfSprite_setPosition(sprite->runner, sprite->pos_runner);
        }
        if (sprite->jump_state == 0) {
            sprite->pos_runner.y += sprite->velocity.y;
            sfSprite_setPosition(sprite->runner, sprite->pos_runner);
        }
        if (sprite->pos_runner.y > 700 && sprite->jump_state == 0)
            sprite->count = 0;
    }
}
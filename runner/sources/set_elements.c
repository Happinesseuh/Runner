/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** set_elements
*/

#include "../includes/my_runner.h"

void set_music(sprite_t *sprite)
{
    sprite->soundbuffer2 = sfSoundBuffer_createFromFile("./assets/music2.ogg");
    sprite->music = sfSound_create();
    sfSound_setBuffer(sprite->music, sprite->soundbuffer2);
}

void set_name(sprite_t *sprite)
{
    sprite->text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/SIXTY.TTF");
    sfText_setFont(sprite->text, font);
    sfText_setString(sprite->text, "MY RUNNER");
    sfText_setCharacterSize(sprite->text, 30);
    sfText_setColor(sprite->text, sfRed);
    sprite->pos_text.x = sfRenderWindow_getSize(sprite->window).x/2 - 150;
    sprite->pos_text.y = sfRenderWindow_getSize(sprite->window).y/2 - 400;
    sfText_scale(sprite->text, init_pos(2, 2));
    sfText_setPosition(sprite->text, sprite->pos_text);
}

void set_score(sprite_t *sprite)
{
    sprite->text_score = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/SIXTY.TTF");
    sfText_setFont(sprite->text_score, font);
    sfText_setString(sprite->text, "score : ");
    sfText_setString(sprite->text_score, int_to_str(sprite->score));
    sfText_setCharacterSize(sprite->text_score, 30);
    sfText_setColor(sprite->text_score, sfRed);
    sprite->pos_text.x = sfRenderWindow_getSize(sprite->window).x/2 + 50;
    sprite->pos_text.y = sfRenderWindow_getSize(sprite->window).y/2 - 400;
    sfText_scale(sprite->text_score, init_pos(2, 2));
    sfText_setPosition(sprite->text_score, sprite->pos_text);
}

void clock_create(sprite_t *sprite, parallax_t *parallax)
{
    parallax->clock_move = sfClock_create();
    sprite->clock_move2 = sfClock_create();
    sprite->clock_move3 = sfClock_create();
}
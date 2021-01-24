/*
** EPITECH PROJECT, 2020
** handle_map.c
** File description:
** handle_map
*/

#include "../includes/my_runner.h"

char *entry_map(char *map)
{
    size_t size = 0;
    FILE *fd = fopen(map, "r");

    if (!fd) {
        my_putstr("Invalid file or path\n");
        return (NULL);
    }
    getline(&map, &size, fd);
    return (map);
}

void move_bloc(sfSprite *sprite)
{
        sfSprite_move(sprite, init_pos(-6, 0));
}

sfSprite *create_bloc(sprite_t *sprite, int i, char c)
{
    sfSprite *bloc;

    if (c == '1')
        bloc = create_sprite(sfTexture_createFromFile("assets/bloc1.png",
        NULL));
    else if (c == '2')
        bloc = create_sprite(sfTexture_createFromFile("assets/bloc2.png",
        NULL));
    else
        bloc = create_sprite(sfTexture_createFromFile("assets/bloc3.png",
        NULL));
    sfSprite_setScale(bloc, init_pos(0.7, 0.7));
    sfSprite_setPosition(bloc, init_pos(i * 380 + 800,
        sfRenderWindow_getSize(sprite->window).y/2 + 350));
    return (bloc);
}

void spawn_obstacles(char *buffer, sprite_t *sprite)
{
    int count = 0;

    sprite->size = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3')
            sprite->size += 1;
    sprite->tab = malloc(sizeof(sfSprite *) * sprite->size + 1);
    sprite->tab[sprite->size] = NULL;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3') {
            sprite->tab[count] = create_bloc(sprite, i, buffer[i]);
            count++;
    }
}
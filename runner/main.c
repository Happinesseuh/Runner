/*
** EPITECH PROJECT, 2020
** mainc
** File description:
** main for my runner
*/

#include "./includes/my_runner.h"

void event(sprite_t *sprite, menu_t *menu)
{
    if (sprite->event.type == sfEvtClosed)
        sfRenderWindow_close(sprite->window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue
            && sprite->count != 1) {
            sprite->count = 1;
            sprite->jump_state = 1;
            sfSound_play(sprite->sound);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            display_pause(menu, sprite);
            menu->pause = 1;
        }
}

void loop_game2(sprite_t *sprite, parallax_t *parallax, menu_t *menu, char *map)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(sprite->window, parallax->para_sprite[i],
        NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->runner, NULL);
    sfRenderWindow_drawText(sprite->window, sprite->text, NULL);
    sfRenderWindow_drawText(sprite->window, sprite->text_score, NULL);
    move_runner(sprite);
    for (sprite->i = 0; sprite->tab[sprite->i] != NULL; sprite->i++) {
            sfRenderWindow_drawSprite(sprite->window, sprite->tab[sprite->i],
            NULL);
            move_bloc(sprite->tab[sprite->i]);
            if (check_collision(sprite->runner, sprite->tab[sprite->i], sprite))
                sprite->hit = 1;
    }
    sprite->bloc_max = sprite->tab[sprite->i - 1];
    if (sprite->bloc_max != NULL)
        sprite->pos_max = sfSprite_getPosition(sprite->bloc_max);
    win_or_lose(sprite);
    if (sprite->hit == 1)
        game_over(sprite);
}

void loop_game(sprite_t *sprite, parallax_t *parallax, menu_t *menu, char *map)
{
    init_and_set_elements(sprite, menu);
    spawn_obstacles(map, sprite);
    while (sfRenderWindow_isOpen(sprite->window)) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
            event(sprite, menu);
        }
        if (sfClock_getElapsedTime(parallax->clock_move).microseconds > 3000) {
            move_bg(sprite, parallax);
            handle_jump(sprite);
            sprite->score++;
            set_score(sprite);
            sfClock_restart(parallax->clock_move);
        }
        loop_game2(sprite, parallax, menu, map);
        sfRenderWindow_display(sprite->window);
    }
}

int my_runner(char *map)
{
    sprite_t sprite;
    menu_t menu;
    parallax_t parallax;
    sfVideoMode mode = {1600, 900, 60};

    sprite.choice = entry_choice();
    while (!(sprite.choice[0] >= '1' && sprite.choice[0] <= '4')
    || (my_strlen(sprite.choice) != 2))
        sprite.choice = entry_choice();
    clock_create(&sprite, &parallax);
    sprite.window = sfRenderWindow_create(mode, "My_runner",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(sprite.window, 60);
    init_runner(&sprite);
    set_parallax(&sprite, &parallax);
    init_menu(&menu, &sprite);
    display_menu(&sprite, &menu);
    loop_game(&sprite, &parallax, &menu, map);
    sfSound_stop(sprite.sound);
    destroy_elements(&sprite, &parallax, &menu);
}

int main(int ac, char **av, char **env)
{
    char *map = NULL;
    if (env[0] == NULL)
        return (84);
    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        print_help();
        return (0);
    }
    map = entry_map(av[1]);
    if (map == NULL)
        return (84);
    if (map[0] == ' ' && map[1] == '\0')
        return (84);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != ' ' && map[i] != '1' && map[i] != '2' && map[i] != '3') {
            my_putstr("Invalid map, use ./my_runner -h\n");
            return (84);
        }
    }
    my_runner(map);
    return 0;
}
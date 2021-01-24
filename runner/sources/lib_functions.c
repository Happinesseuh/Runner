/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** lib_functions
*/

#include "../includes/my_runner.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return (1);
        }else if (s1[i] < s2[i]) {
            return (-1);
        }
    }
    if (s1[i] == s2[i]){
        return (0);
    }
}

void my_putchar(char c)
{
    write(1, &c,  1);
}

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return x;
}

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        x++;
    }
    return x;
}
/*
** EPITECH PROJECT, 2021
** B-MUL-100-PAR-1-1-myrunner-ines.maaroufi
** File description:
** lib_functions2
*/

#include "../includes/my_runner.h"

int my_intlen(int nb)
{
    int x = 0;

    for (; nb != 0; x++) {
        nb /= 10;
    }
    return x;
}

char *my_revstr(char *str)
{
    int i = 0;
    int n = my_strlen(str) - 1;
    int x;

    while (i < n) {
        x = str[i];
        str[i] = str[n];
        str[n] = x;
        i++;
        n--;
    }
    return (str);
}

char *int_to_str(int nb)
{
    char *result = malloc(sizeof(char) * my_intlen(nb));

    for (int i = 0; nb != 0; i++) {
        result[i] = (nb % 10) + '0';
        nb /= 10;
    }
    my_revstr(result);
    return (result);
}

int my_str_isnum(char const *str)
{
    int nb = 0;
    int alpha = my_strlen(str);

    if (str[0] == '\0') {
        return (1);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb++;
        }
    }
    if (nb == alpha) {
        return (1);
    } else {
        return (0);
    }
}

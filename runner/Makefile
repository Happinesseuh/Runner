##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for project my_hunter
##

SRC	=	./sources/set_menu.c\
		./sources/parallax.c\
		./sources/sprite_runner.c\
		./sources/handle_map.c\
		./sources/lib_functions.c\
		./sources/lib_functions2.c\
		./sources/set_pause.c\
		./sources/set_elements.c\
		./sources/set_sprite_buttons.c\
		./sources/set_jump.c\
		./sources/win_or_lose.c\
		./sources/init_and_destroy_elements.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	compile clean

compile:	$(OBJ)
	gcc $(OBJ) -o $(NAME) -g -Wall -Wextra -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window

re:	fclean compile clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *vgcore*
	rm -f a.out
	rm -rf .vscode
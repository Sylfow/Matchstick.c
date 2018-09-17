##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make re
##

SRC	=	src/main.c	\
		src/game.c	\
		src/map.c	\
		src/ia.c	\
		src/play_board.c	\
		src/get_next_line.c	\
		src/xmalloc.c	\
		src/str.c	\
		src/verif.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall -Wextra -Iincl -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L.

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

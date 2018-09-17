/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of matchstick
*/

#include "matchstick.h"

int error(gm_t *gm, int ac, char **av)
{
	if (ac != 3) {
		my_putstr("Bad number of arguments.\n");
		return (84);
	}
	if ((gm->size = my_getnbr(av[1])) < 2 || gm->size > 99)
		return (84);
	if ((gm->max_stick = my_getnbr(av[2])) < 1)
		return (84);
	return (0);
}

int win_condition(gm_t *gm)
{
	int x = 1;
	int y = 1;

	while (y <= gm->size) {
		if (x == '*') {
			x = 1;
			y = y + 1;
		}
		if (gm->board[y][x] == '|')
			return (0);
		x = x + 1;
	}
	return (1);
}

int win(int win)
{
	if (win == 1) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	} else {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
}

int game(gm_t *gm)
{
	static int player = 1; 

	if (player == 1) {
		my_putstr("Your turn:\n");
		if (player_turn(gm) == -1)
			return (0);
		player = 2;
	} else {
		my_putstr("AI's turn...\n");
		ia_turn(gm);
		player = 1;
	}
	return (player);
}

int main(int ac, char **av)
{
	gm_t gm;

	if (error(&gm, ac, av) == 84)
		return (84);
	gm.board = add_map(gm.size);
	print_map(gm.board, gm.size);
	my_putchar('\n');
	srand(time(NULL));
	while (win_condition(&gm) == 0)
		if ((gm.win = game(&gm)) == 0)
			return (0);
	print_map(gm.board, gm.size);
	free(gm.board);
	win(gm.win);
	return (gm.win);
}

/*
** EPITECH PROJECT, 2018
** play_board.c
** File description:
** change board game
*/

#include "matchstick.h"

int test_stick(char **map, int line, int matches, int ia)
{
	int n_sticks = 0;
	int x = 1;

	while (map[line][x] != '*') {
		if (map[line][x] == '|')
			n_sticks = n_sticks + 1;
		x = x + 1;
	}
	if (n_sticks < matches) {
		if (ia == 0)
			my_putstr("Error: not enough matches on this line\n");
		return (1);
	} else
		return (0);
}

int test_line(char **map, int line)
{
	int x = 1;

	while (map[line][x] != '*') {
		if (map[line][x] == '|')
			return (0);
		x = x + 1;
	}
	return (1);
}

char **drop_the_stick(char **map, int line, int matches)
{
	int x;
	int drop;

	for (x = 1; (map[line][x] != '|' ||
		     map[line][x + 1] != ' ') &&
		     (map[line][x + 1] != '*'); x++);
	for (drop = 0; drop < matches; drop++) {
		map[line][x] = ' ';
		x = x - 1;
	}
	return (map);
}

void text(int line, int matches, char *name)
{
	my_putstr(name);
	my_putstr(" removed ");
	my_put_nbr(matches);
	my_putstr(" matches from line ");
	my_put_nbr(line);
	my_putchar('\n');
}

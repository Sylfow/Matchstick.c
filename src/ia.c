/*
** EPITECH PROJECT, 2018
** ia
** File description:
** ia game mode
*/

#include "matchstick.h"

int random_nbr(int min, int max)
{
	return((rand() % (max - min)) + min);
}

int count_matches(char *line)
{
	int i = 0;
	int count = 0;

	while (line[i] != '\0') {
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void ia_turn(gm_t *gm)
{
	int line;
	int matches;

	line = random_nbr(1, gm->size + 1);
	while (count_matches(gm->board[line]) == 0)
		line = random_nbr(1, gm->size + 1);
	while ((matches = random_nbr(1, gm->max_stick + 1))
	       > count_matches(gm->board[line]))
		matches = random_nbr(1, gm->max_stick + 1);
	gm->board = drop_the_stick(gm->board, line, matches);
	text(line, matches, "IA");
	if (win_condition(gm) == 0) {
		print_map(gm->board, gm->size);
		my_putchar('\n');
	}
}

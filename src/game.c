/*
** EPITECH PROJECT, 2018
** game
** File description:
** game matchstick
*/

#include <matchstick.h>

int get_nb_line(void)
{
	char *line = NULL;
	int i = 0;

	if ((line = get_next_line(0)) == NULL)
		return (-2);
	if (line[0] == '\0') {
		my_putstr("Error: invalid input ");
		my_putstr("(positive number expected)\n");
		return (-1);
	}
	while (line[i]) {
		if ((line[i] < '0' || line[i] > '9') && line[i] != ' ') {
			my_putstr("Error: invalid input ");
			my_putstr("(positive number expected)\n");
			return (-1);
		}
		i = i + 1;
	}
	return (my_getnbr(line));
}

int line_stick(char **board, int line)
{
	int x = 1;

	while (board[line][x] != '*') {
		if (board[line][x] == '|')
			return (1);
		x = x + 1;
	}
	return (-1);
}

int take_line(gm_t *gm, int line)
{
	while (line == 0) {
		my_putstr("Line: ");
		if ((line = get_nb_line()) == -2) {
				return (-2);
		}
		if (line == -1) {
			line = 0;
			continue;
		}
		if (line <= 0 || line > gm->size) {
			line = 0;
			my_putstr("Error: this line is out of range\n");
		} else if (line_stick(gm->board, line) == -1) {
			line = 0;
			my_putstr("Error: not enough matches on this line\n");
		}
	}
	return (line);
}

int nb_matches(gm_t *gm, int line, int matches)
{
	my_putstr("Matches: ");
	if ((matches = get_nb_line()) <= -1) {
		if (matches == -2)
			return (-2);
		return (-1);
	}
	if (matches == 0) {
		my_putstr("Error: you have to remove at least one ");
		my_putstr("match\n");
		return (-1);
	}
	if (gm->max_stick < matches) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	if (test_stick(gm->board, line, matches, 0) == 1)
		return (-1);
	return (matches);
}

int player_turn(gm_t *gm)
{
	int line = 0;
	int matches = 0;
	int errno = 0;

	while (errno == 0) {
		if (verif(gm, &line, &matches, &errno) == -1)
			return (-1);
	}
	gm->board = drop_the_stick(gm->board, line, matches);
	text(line, matches, "Player");
	if (win_condition(gm) == 0) {
		print_map(gm->board, gm->size);
		my_putchar('\n');
	}
	return (2);
}

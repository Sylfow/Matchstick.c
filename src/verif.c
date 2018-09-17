/*
** EPITECH PROJECT, 2018
** verif
** File description:
** verif player inpute
*/

#include "matchstick.h"

int verif(gm_t *gm, int *line, int *matches, int *errno)
{
	if ((*line = take_line(gm, *line)) == -2)
		return (-1);
	*errno = 1;
	if ((*matches = nb_matches(gm, *line, *matches)) == -2)
		return (-1);
	if (*matches == -1) {
		*errno = 0;
		*line = 0;
	}
	return (0);
}

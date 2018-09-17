/*
** EPITECH PROJECT, 2018
** map
** File description:
** map of matchstick
*/

#include <matchstick.h>

char **end_of_line(char **map, int size, int x, int y)
{
	for (x = 0; x <= (2 * size + 1); x++) {
		map[y][x] = '*';
		if (x == (2 * size + 1))
			map[y][x] = '\0';
	}
	return (map);
}

char **add_pipe(char **map, int size, int x, int y)
{
	int n_max = size * 2 - 1;
	int n_stick = y * 2 - 1;
	int put_stick = 0;

	map[y][0] = '*';
	for (x = 1; x <= (n_max - n_stick) / 2; x++) {
		map[y][x] = ' ';
		put_stick = put_stick + 1;
	}
	for (x = x; x <= n_stick + put_stick; x++)
		map[y][x] = '|';
	put_stick = x;
	for (x = x; x < size * 2; x++)
		map[y][x] = ' ';
	map[y][size * 2] = '*';
	map[y][size * 2 + 1] = '\0';
	return (map);
}

char **add_map(int size)
{
	char **map;
	int x = 0;
	int y = 0;

	if ((map = xmalloc(sizeof(char *) * (size + 2))) == NULL)
		return (NULL);
	while (y <= size + 1) {
		if ((map[y] = xmalloc(sizeof(char) * (size * 2 + 1))) == NULL)
			return (NULL);
		if (y == 0 || y == (size + 1))
			map = end_of_line(map, size, x, y);
		else
			map = add_pipe(map, size, x, y);
		y = y + 1;
	}
	y = y - 2;
	return (map);
}

void print_map(char **map, int size)
{
	int y = 0;

	while (y <= size + 1) {
		my_putstr(map[y]);
		my_putchar('\n');
		y = y + 1;
	}
}

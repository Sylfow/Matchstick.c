/*
** EPITECH PROJECT, 2018
** str
** File description:
** some str function
*/

#include "matchstick.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
}

int my_strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++);
	return (i);
}

void my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	 if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else
		my_putchar(nb + 48);
}

int my_getnbr(char *str)
{
	int i = 0;
	int n = 0;

	if (str[0] == '-' && str[1] != '\0')
		i = i + 1;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			my_putstr("Error: invalid input ");
			my_putstr("(positive number expected)\n");
			return (-1);
		}
		n = n + str[i] - 48;
		n = n * 10;
		i = i + 1;
	}
	n /= 10;
	if (str[0] == '-')
		return (-1 * n);
	else
		return (n);
}

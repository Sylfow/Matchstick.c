/*
** EPITECH PROJECT, 2018
** xmalloc
** File description:
** test malloc
*/

#include <matchstick.h>

void *xmalloc(size_t size)
{
	void *p = malloc(size);

	if (p == NULL) {
		my_putstr("Error: Fail to malloc\n");
		return (NULL);
	}
	return (p);
}

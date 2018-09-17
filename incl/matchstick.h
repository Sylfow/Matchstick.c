/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** headers
*/

#ifndef MATCHSTICK_
#define MATCHSTICK_

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif

typedef struct game {
        char **board;
        int size;
        int max_stick;
        int win;
} gm_t;

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *s);
void my_put_nbr(int nb);
void *xmalloc(size_t size);
int my_getnbr(char *str);
char *get_string(char *s, char *s2);
void get_string2(char *s2, int fd);
char *my_strcat(char *s2, char *s);
char *get_next_line(int fd);
char **end_of_line(char **map, int size, int x, int y);
char **add_pipe(char **map, int size, int x, int y);
char **add_map(int size);
void print_map(char **map, int size);
int win_condition(gm_t *gm);
int test_stick(char **map, int line, int matches, int ia);
int test_line(char **map, int line);
int verif(gm_t *gm, int *line, int *matches, int *errno);
char **drop_the_stick(char **map, int line, int matches);
int player_turn(gm_t *gm);
void ia_turn(gm_t *gm);
void text(int line, int matches, char *name);
char **drop_the_stick(char **map, int line, int matches);
int get_nb_line(void);
int line_stick(char **board, int line);
int take_line(gm_t *gm, int line);
int nb_matches(gm_t *gm, int line, int matches);
int random_nbr(int min, int max);
int game(gm_t *gm);
int main(int ac, char **av);

#endif /* MATCHSTICK */

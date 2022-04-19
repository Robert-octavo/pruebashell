CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

main: shell_09.c findpath.c envfunc.c t_string.c builtin.c
	$(CC) $(CFLAGS) findpath.c t_string.c envfunc.c builtin.c shell_09.c  -o shell_09 && ./shell_09
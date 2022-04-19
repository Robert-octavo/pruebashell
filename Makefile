CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

main: shell_10.c findpath.c envfunc.c t_string.c builtin.c
	$(CC) $(CFLAGS) findpath.c t_string.c envfunc.c builtin.c shell_10.c  -o shell_10 && ./shell_10
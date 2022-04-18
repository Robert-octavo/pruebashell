#include "shell.h"
/**
 * builtin - Funtion that call the env or the exit
 * 
 * 
 * Return: Integer 
 */
int builtin(char *comando[])
{
    int res = 0;
    printf("%s", comando[0]);
    if (str_compare(comando[0], "exit", 4) == 0)
			return (1);
		else if (str_compare(comando[0], "env", 3) == 0)
		{
			print_env();
			return (1);
        }
    return (res);

}
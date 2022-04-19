#include "shell.h"
/**
 * builtin - Funtion that call the env or the exit
 *
 * @comando: comando a verificar
 * Return: Integer
 */
 int *builtin(char *comando)
{
    if (str_compare(comando, "exit", 4) == 0)
        exit(EXIT_SUCCESS);
    else if (str_compare(comando, "env", 3) == 0)
        print_env();
    return (0);
}
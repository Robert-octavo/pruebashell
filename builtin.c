#include "shell.h"
/**
 * builtin - Funtion that call the env or the exit
 *
 * @comando: comando a verificar
 * Return: Integer
 */
 int builtin(char *comando)
{
    if (str_compare(comando, "exit", 4) == 0)
    {
        free(comando);
        exit(EXIT_SUCCESS);
        return (1);
    }else if (str_compare(comando, "env", 3) == 0)
    {
        print_env();
        free(comando);
        return (1);
    }else
        return (0);
}
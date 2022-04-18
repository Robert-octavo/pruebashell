#include "shell.h"
/**
* main - Unix command line
* Return: Always 0
*/
int main(/*int argc, char *argv[], char *envp[]*/)
{
	pid_t hijo;
	char *comando[100], *token = NULL, *linea = NULL;
	char *path_com = NULL; /*PATH + comando*/
	size_t n, i;
	int status = 0;/* function = 0;*/

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		fflush(stdin);
		if (getline(&linea, &n, stdin) == -1)
			break;
		if (*linea == '\n' || *linea == '\t') /*correct error - Permission denied when press enter*/
			continue;
		token = strtok(linea, " ");
		printf("%s", token);
		comando[0] = token;
		printf("%s", comando[0]);
		for (i = 0; token != NULL; i++)
		{
			comando[i] = token;
			token = strtok(NULL, " \t\n\r");
		}
		comando[i] = NULL;

		//printf("comando [%s] ", comando[0]);
		/*if (str_compare(comando[0], "exit", 4) == 0)
			return (0);
		else if (str_compare(comando[0], "env", 3) == 0)
		{
			print_env();
			function = 1;
		}*/

		path_com = findpath(comando[0]);
		//builtin(comando);
		if (builtin(comando) == 0)
		{
			hijo = fork();
			if (hijo == 0)
			{
				if (execve(path_com, comando, NULL))
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			if (hijo > 0)
			{
				wait(&status);
			}
		}
		linea = NULL;
		token = NULL;
		comando[0] = NULL;
	}
	//free(linea);
	exit(status);
}

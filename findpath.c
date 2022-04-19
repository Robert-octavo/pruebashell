#include "shell.h"

/**
 * findpath -Funtion that find the PATH where the command is save
 * @comando: Pointer - Command to find the path
 * Return: the PATH with the command to execute*
 */

char *findpath(char *comando)
{
	char *path = NULL, *ctoprint = NULL;
	struct stat stats;
	char *token = NULL, *auxpath = NULL;
	int i = 0;
	/*char *c_source;*/

	if (stat(comando, &stats) == 0)
		return (comando);
	path = _getenv("PATH");
	auxpath = malloc(strlen(path) + 1);
	auxpath = strcpy(auxpath, path);
	token = strtok(auxpath, ":\n");
	comando = str_concat("/", comando);
	/*printf("desde el findpath [%s]",comando);*/
	/*
	*stat() return 0 on successful
	*returns -1 if its unable to get file
	*properties
	*/
	while (token != NULL)
	{
		ctoprint = str_concat(token, comando);

		if (stat(ctoprint, &stats) == 0)
		{
			free(comando);
			free(auxpath);
			return (ctoprint);
		}
		free(ctoprint);
		token = strtok(NULL, ":\n");
		i++;
	}
	/*printf("\nComando a ejecutar: %s", ctoprint);*/
	free(comando);
	free(auxpath);
	return (NULL);
}

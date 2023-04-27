#include "main.h"
/**
* handle_path - handles the path in a shell
* @args: the arguments passes in
* Description: A functions that handles shell path
* Return: the path as a sommand
*/
char *handle_path(char **args)
{
	char *path;
	char *command;
	char filename[MAX_INPUT_LENGTH];
	char *path_duplicate;
	char *token;
	int path_len;

	path = my_getenv("PATH");
	command = args[0];
	path_duplicate = (char *)malloc((my_strileng(path) + 1) * sizeof(char));
	if (path_duplicate == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	my_strcpy(path_duplicate, path);
	token = my_strtok(path_duplicate, ":");
	while (token != NULL)
	{
		path_len = my_strileng(token);

		my_strcpy(filename, token);
		if (filename[path_len - 1] != '/')
		{
			my_strcat(filename, "/");
		}
		my_strcat(filename, command);

		if (access(filename, X_OK) == 0)
		{
			command = filename;
			break;
		}

		token = my_strtok(NULL, ":");
	}
	free(path_duplicate);

	return (command);
}

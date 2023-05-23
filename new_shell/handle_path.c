#include "main.h"

/**
 * * handle_path - handles the path
 * * @args: arguments
 * * Return: void
 * */
char *handle_path(char **args)
{
	char *path;
	char *command = args[0];
	char filename[MAX_INPUT_LENGTH];
	char *path_duplicate;
	char *token;
	int path_len;

	path = my_getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_duplicate = (char *)malloc((my_strlen(path) + 1) * sizeof(char));
	if (path_duplicate == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	my_strcpy(path_duplicate, path);
	token = strtok(path_duplicate, ":");

	while (token != NULL)
	{
		path_len = my_strlen(token);

		my_strcpy(filename, token);
		if (filename[path_len - 1] != '/')
		{
			my_strcat(filename, "/");
		}
		my_strcat(filename, command);

		if (access(filename, F_OK | X_OK) == 0)
		{
			command = filename;
			free(path_duplicate);
			return (command);
		}
		token = strtok(NULL, ":");
	}
	free(path_duplicate);
	return (NULL);
}


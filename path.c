#include "main.h"

char *handle_path(char **args)
{
	char *path;
	char *command;
	char filename[MAX_INPUT_LENGTH];
	char *path_duplicate;
	char *token;
	int path_len;

	path = getenv("PATH");

	command = args[0];

	path_duplicate = (char *)malloc((strlen(path) + 1) * sizeof(char));
	if (path_duplicate == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	strcpy(path_duplicate, path);

	token = my_strtok(path_duplicate, ":");

	while (token != NULL)
	{
		path_len = strlen(token);

		strcpy(filename, token);
		if (filename[path_len - 1] != '/')
		{
			strcat(filename, "/");
		}
		strcat(filename, command);

		if (access(filename, X_OK) == 0)
		{
			command = filename;
			break;
		}

		token = my_strtok(NULL, ":");
	}

	free(path_duplicate);

	return command;
}


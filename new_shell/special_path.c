#include "main.h"

/**
 * handle_special_path - Handles special paths for commands.
 * @args: The array of command arguments.
 *
 * Return: the command if it exists or NULL if it doesn't
 */

char *handle_special_path(char **args)
{
	char *path;
	char *command = args[0];

	path = my_getenv("PATH");

	if (path == NULL)
		return (command);

	if (my_strstr(command, "/") != NULL)
	{
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		return (NULL);
	}

	return (NULL);
}


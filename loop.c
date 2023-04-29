#include "main.h"
/**
 * loop - loops throu functions
 * Return: void
 */
void loop(void)
{
	char *input = NULL;
	char **args = NULL;
	int status = 1;
	int interger = 1;

	if (isatty(STDIN_FILENO) != 1)
		interger = 0;
	do {
		if (interger != 0)
		{
			my_printf("$ ");
		}
		input = kpsh_get_input();

		if (input == NULL)
		{
			continue;
		}
		args = kpsh_split_strings(input);

		if (args == NULL)
		{
			free(input);
			continue;
		}

		if (args[0] == NULL)
		{
			free(input);
			free(args);
			continue;
		}

		status = execute_command(args, input);

		free(input);
		free(args);

	} while (status);
}


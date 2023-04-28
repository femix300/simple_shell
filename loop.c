#include "main.h"
/**
* loop - loops throu functions
* Return: void
*/

void loop(void)
{
	char *input;
	char **args;
	int status;
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
			return;

		args = kpsh_split_strings(input);

		if (args == NULL)
		{
			free(input);
			return;
		}

		status = execute_command(args);

		free(input);
		free(args);

	} while (status);
}


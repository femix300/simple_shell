#include "main.h"
/**
* loop - a function that loops through other shell functions
*
* Description: How to loop
* Return: nothing
*/

void loop(void)
{
	char *input;
	char **args;
	int status;

	do {
		my_printf("$ ");
		fflush(stdout);
		input = kpsh_get_input();
		args = kpsh_split_strings(input);
		status = execute_command(args);

		free(input);
		free(args);

	} while (status);
}


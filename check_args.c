#include "main.h"
/**
* check_args - checks if arguments are null
* @args: arguments
* @input: input string
* Return: 1 if true
*/
int check_args(char **args, char *input)
{
	if (args[0] == NULL)
	{
		free(input);
		return (1);
	}

	return (1);
}

#include "main.h"


/**
 * kpsh_exit - Prompt to exit the shell
 *
 * @args: Arguments for exit string
 * @num_args: Number of arguments
 * Description: A function on how to exit
 * Return: Error
 */
void kpsh_exit(char **args, int num_args)
{
	if (num_args == 1)
	{
		exit(0);
	}
	else if (num_args == 2)
	{
		exit(my_atoi(args[1]));
	}
	else
	{
		perror("Error");
		return;
	}
}


#include "main.h"
/**
* get_num_args - a function that counts the njumber of arguments
* @args: the arguments
* Return: the number of arguments
*/

int get_num_args(char **args)
{
	int num_args;

	num_args = 0;

	while (args[num_args] != NULL)
	{
		num_args++;
	}

	return (num_args);
}

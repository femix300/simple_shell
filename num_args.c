#include "main.h"

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

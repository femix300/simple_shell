#include "main.h"
/**
* set_env - sets the environ var
* @args: arguments
* Return: void
*/

void set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		perror("Error:");
		return;
	}

	if (my_setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
* unset_env - unsets the environ variable
* @args: arguments
* Return: void
*/
void unset_env(char **args)
{
	if (args[1] == NULL || args[2] != NULL)
	{
		perror("Error");
		return;
	}

	if (my_unsetenv(args[1]) != 0)
	{
		perror("Error");
	}
}

#include "main.h"
/**
* set_env - sets the environmental variable
* @args: arguments passed into the shell
* Description: How to set an environmental variable
* Return: nothing
*/
void set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		perror("Error:");
		return;
	}

	if (my_setenv(args[1], args[2]) != 0)
	{
		perror("setenv");
	}
}

/**
* unset_env - unsets environmental variable
* @args: arguments passed into the shell
* Description: This functions unsets an environmental var
* Return: nothing
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

#include "main.h"

/**
 * kpsh_exit - exits'the shell
 * @args: arguments
 * Return: void
 */
void kpsh_exit(char **args)
{
	int num_args = 0;

	while (args[num_args] != NULL)
		num_args++;

	if (num_args == 1)
	{
		free_bufs(args);
		exit(0);
	}
	else if (num_args == 2)
	{
		free_bufs(args);
		exit(my_atoi(args[1]));
	}
	else
	{
		perror("Error");
		return;
	}
}

/**
 * set_env - sets the environ var
 * @args: arguments
 * Return: void
 */
void set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		perror("setenv error");
		return;
	}

	if (my_setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv error");
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
		perror("unsetenv error");
		return;
	}

	if (my_unsetenv(args[1]) != 0)
	{
		perror("unsetenv error");
	}
}

/**
 * change_directory - changes the directory
 * @args: the arguments
 * Return: nothing
 */

void change_directory(char **args)
{
	char *home_dir;
	static char prev_dir[MAX_COMMAND_LENGTH];
	char *target_dir;
	char cwd[MAX_COMMAND_LENGTH];

	home_dir = my_getenv("HOME");
	if (args[1] == NULL || my_strcmp(args[1], "~") == 0)
	{
		target_dir = home_dir;
	}
	else if (my_strcmp(args[1], "-") == 0)
	{
		target_dir = prev_dir;
	}
	else
	{
		target_dir = args[1];
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return;
	}

	if (chdir(target_dir) == 0)
	{
		my_strncpy(prev_dir, cwd, MAX_COMMAND_LENGTH);

		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd() error");
			return;
		}

		my_setenv("PWD", cwd, 1);
	}
	else
	{
		cd_error_message("cd: ");
		cd_error_message(target_dir);
		cd_error_message(": No such file or directory\n");
	}
}

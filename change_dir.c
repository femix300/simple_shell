#include "main.h"

void change_directory(char **args)
{
	char *home_dir;
	static char prev_dir[MAX_COMMAND_LENGTH];
	char *target_dir;
	char cwd[MAX_COMMAND_LENGTH];

	home_dir = getenv("HOME");

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		target_dir = home_dir;
	}
	else if (strcmp(args[1], "-") == 0)
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
		strncpy(prev_dir, cwd, MAX_COMMAND_LENGTH);

		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd() error");
			return;
		}

		my_setenv("PWD", cwd, 1);
	}
	else
	{
		my_printf("cd: %s: No such file or directory\n", target_dir);
	}
}


#include "main.h"

int execute_command(char **args)
{
	pid_t pid;
	int status;
	int num_args;
	char *command;

	if (args[0] == NULL)
		return (1);

	if (strcmp(args[0], "exit") == 0)
	{
		num_args = get_num_args(args);
		kpsh_exit(args, num_args);
	}
	else if(strcmp(args[0], "cd") == 0)
	{
		change_directory(args);
		return (1);
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		set_env(args);
		return 1;
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		unset_env(args);
		return 1;
	}


	command = handle_path(args);

	if (access(command, X_OK) != 0)
	{
		my_printf("%s: command not found\n", args[0]);
		return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
	{
		do 
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}


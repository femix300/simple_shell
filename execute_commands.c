#include "main.h"

/**
* execute_command - execute shell commands
* @args: arguments to thr commands
* Return: 1 or 0
*
*/
int execute_command(char **args)
{
	pid_t pid;
	int status;
	int num_args;
	char *command;

	if (args[0] == NULL)
		return (1);
	if (my_strcmp(args[0], "exit") == 0)
	{
		num_args = get_num_args(args);
		kpsh_exit(args, num_args);
	}
	else if (my_strcmp(args[0], "cd") == 0)
	{
		change_directory(args);
		return (1);
	}
	else if (my_strcmp(args[0], "setenv") == 0)
	{
		set_env(args);
		return (1);
	}
	else if (my_strcmp(args[0], "unsetenv") == 0)
	{
		unset_env(args);
		return (1);
	}
	command = handle_path(args);
	if (access(command, X_OK) != 0)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", "./hsh", 1, args[0]);
		/*my_printf("%s: command not found\n", args[0]);*/
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			perror("Error: ");
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
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}


#include "main.h"
#include "builtins.h"
/**
 * execute_command - executes the commands entered
 * @args: the arguments
 * @input: the input string
 * Return: 1
 */

int execute_command(char **args, char *input)
{
	pid_t pid;
	int status;
	int i;
	char *command;

	check_args(args, input);

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (my_strcmp(args[0], builtins[i].name) == 0)
		{
			(builtins[i].func(args));
			return (1);
		}
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
		if (execve(command, args, environ) < 0)
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
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}


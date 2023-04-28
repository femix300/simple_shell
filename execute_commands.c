#include "main.h"

/**
 * execute_command - execute shell commands
 *
 * @args: arguments to the commands
 *
 * Description: This functions calls all built-in functions
 *
 * Return: 1
 *
 */
int execute_command(char **args)
{
	int stat, pid;
	int flg = 0;
	
	args = my_chpath(args, &flg);
	
	if (args == NULL)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("hsh");
		}
		if (flg == 1)
		free(args[0];
		return (-1);
	}
	else if (pid < 0)
	{
		perror("hsh:");
		if (flg == 1)
		free(args[0]);
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (flg == 1)
	free(args[0]);
	

	return (1);
}

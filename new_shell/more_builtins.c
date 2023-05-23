#include "main.h"

/**
 * remove_quotes - Removes quotes from a string.
 * @str: The string to remove quotes from.
 */
void remove_quotes(char *str)
{
	int len = strlen(str);
	int read_pos = 0;
	int write_pos = 0;

	while (read_pos < len)
	{
		if (str[read_pos] != '"')
		{
			str[write_pos] = str[read_pos];
			write_pos++;
		}
		read_pos++;
	}

	str[write_pos] = '\0';
}

/**
 * expand_and_print_env_variable - Expands and prints the
 *                                 value of an environment variable.
 * @variable: The name of the environment variable.
 */

void expand_and_print_env_variable(const char *variable)
{
	char *value;

	value = my_getenv(variable);
	if (value != NULL)
	{
		write(STDOUT_FILENO, value, my_strlen(value));
	}
	else
	{
		write(STDOUT_FILENO, "$", 1);
		write(STDOUT_FILENO, variable, my_strlen(variable));
	}
}

/**
 * builtin_echo - Implements the 'echo' built-in command.
 * @args: The array of arguments passed to the command.
 */

void builtin_echo(char **args)
{
	int i = 1;
	while (args[i] != NULL)
	{
		if (args[i][0] == '$')
		{
			expand_and_print_env_variable(&args[i][1]);
		}
		else
		{
			remove_quotes(args[1]);
			write(STDOUT_FILENO, args[i], my_strlen(args[i]));
		}
		if (args[i + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1);
		}
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * print_env - Prints the environment variables.
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		int i = 0;
		while ((*env)[i] != '\0')
		{
			write(STDOUT_FILENO, &((*env)[i]), 1);
			i++;
		}
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

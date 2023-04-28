#include "main.h"
/**
 * my_loop - a function that loops through other shell functions
 *
 * Description: How to loop
 * Return: nothing
 */

void my_loop(void)
{
	char *inp;
	char **args;
	int interger = 1, leng;
	int stat;

	if (isatty(STDIN_FILENO) != 1)
		interger = 0;

	do {
		if (interger != 0)
		{
			leng = my_strileng("$ ");
			write(STDOUT_FILENO, "$ ", leng);
		}

		inp = my_linere();
		if (inp == NULL)
			return;

		args = kpsh_split_strings(inp);
		if (args == NULL)
		{
			free(inp);
			return;
		}

		stat = exec_cm(args);

		free(inp);
		free(args);

	} while (stat == 1);
}


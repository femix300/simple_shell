#include "main.h"

/**
 * kpsh_get_input - a function that gets user input from
 * stdin
 * Return: the input gotten from the user as a string
 */   

char *get_input(void)
{
	char *input = NULL;
	size_t bufsize;
	ssize_t line_len;

	bufsize = 0;
	line_len = getline(&input, &bufsize, stdin);

	if (line_len < 0)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		free(input);
		perror("getinput");
		exit(EXIT_FAILURE);
	}

	if (input[line_len - 1] == '\n')
		input[line_len - 1] = '\0';

	return (input);
}

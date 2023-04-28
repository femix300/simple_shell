#include "main.h"
/**
 * kpsh_split_strings - splits user string into argumetns(tokens)
 * @str: String to be splitted
 * Description: Spliting tokens
 * Return: an array of strings gotten from the string
 */
char **kpsh_split_strings(char *str)
{
	int buffsize, i;
	char **tokens;
	char *token;

	buffsize = BUFF_SIZE;
	i = 0;

	tokens = malloc(buffsize * sizeof(char *));
	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = my_strtok(str, DELIMITER);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= buffsize)
		{
			buffsize += BUFF_SIZE;
			tokens = my_realloc(tokens, buffsize * sizeof(char *));
			if (tokens == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}

		token = my_strtok(NULL, DELIMITER);
	}

	tokens[i] = NULL;

	return (tokens);
}

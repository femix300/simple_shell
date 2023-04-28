#include "main.h"

/**
 * my_pathsplt - A function that splits PATH string
 *
 * @sent: Line to be splited
 * @path_duplicate: Path directory
 *
 * Description: How PATH command is parsed
 *
 * Return: Tokens splitted
 */
char **my_pathsplt(char *sent, char *path_duplicate)
{
	int buffsize = 1024, pos = 0;
	char **tokens;
	char *token;
	char *delimiter = ":\r\n\a";

	tokens = malloc(buffsize * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: Error\n");
		return (NULL);
	}
	my_strcpy(path_duplicate, sent);
	if (*path_duplicate == *delimiter)
	{
		*path_duplicate = '\0';
		tokens[pos] = path_duplicate;
		pos++;
	}
	token = my_strtok(path_duplicate, delimiter);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= buffsize)
		{
			buffsize += 1024;
			tokens = my_realloc(tokens, buffsize * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: Error\n");
				return (NULL);
			}
		}
		token = my_strtok(NULL, delimiter);
	}
	tokens[pos] = NULL;
	return (tokens);
}

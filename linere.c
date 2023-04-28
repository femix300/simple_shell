#include "main.h"

/**
 * my_linere - Command prompt read line
 *
 * Description: A function that reads a line"
 *
 * Return: Pointer to the read line
 *
 */
char *my_linere(void)
{
	char *sent = NULL;
	size_t buffsize = 0;
	ssize_t getre;

	getre = getline(&sent, &buffsize, STDIN_FILENO);
	if (getre == -1)
	{
		free(sent);
		return (NULL);
	}
	return (sent);
}

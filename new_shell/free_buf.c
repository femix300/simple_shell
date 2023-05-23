#include "main.h"

/**
 * free_bufs - Frees the memory allocated for a buffer.
 * @buffer: The buffer to be freed.
 */
void free_bufs(char **buffer)
{
	int i; 

	if (buffer == NULL)
		return;

	for (i = 0; buffer[i] != NULL; i++)
	{
		free(buffer[i]);
	}

	free(buffer);
}


#include "main.h"

/**
 * free_bufs - Frees the memory.
 * @buffer: Freed buffer.
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


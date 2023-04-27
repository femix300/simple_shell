#include "main.h"

/**
 * my_strcat - concatenates two strings from src to dest
 * @dest: destination string
 * @src: source string
 * Description: This function concatenates strings
 * Return: pointer to the resulting string dest
 */

char *my_strcat(char *dest, const char *src)
{
	int a, b;

	a = 0;
	while (dest[a] != '\0')
		a++;
	b = 0;
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * my_realloc - implementation of realloc function
 * @ptr: pointer to the old block of memory
 * @new_size: size of the new block of memory
 * Description: How to implement Realloc system function
 *
 * Return: pointer to the new block of memory
 */
void *my_realloc(void *ptr, unsigned int new_size)
{
	void *new_ptr;
	size_t old_size = ptr ? sizeof(*((char *) ptr)) * new_size : 0;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		my_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * my_memcpy - a function that copies memory area
 *
 * @dest: memory where is stored
 * @src: memory where is copied
 * @n: number of bytes
 *
 * Description: How to copy memory area
 *Return: copied memory with n byted changed
 */
char *my_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

/**
 * my_strncmp - Compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compare
 *
 * Description: A function that compares strings
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * my_getenv - It returns the value environment variable
 *
 * @name: Environment name
 *
 * Description: Environmental variable
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *my_getenv(const char *name)
{
	int name_len = my_strileng(name);
	char *var;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (my_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			var = *env + name_len + 1;
			return (var);
		}
	}
	return (NULL);
}

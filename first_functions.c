#include "main.h"

/**
 * my_strchr - locate character in string
 * @str: pointer to the string to be searched
 * @ch: character to be located
 *
 * Return: pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *my_strchr(const char *str, int ch)
{
	while (*str != '\0' && *str != ch)
	{
		++str;
	}

	if (*str == ch)
	{
		return ((char *)str);
	}

	else
	{
		return (NULL);
	}
}

/**
 * my_strtok - A function that tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter to use for tokenization
 *
 * Return: A pointer to the next token or NULL if no more tokens are found
 */
char *my_strtok(char *str, const char *delim)
{
	static char *last_str;
	char *start, *end;

	if (str != NULL)
	{
		last_str = str;
	}

	if (last_str == NULL)
	{
		return (NULL);
	}

	start = last_str;
	while (*start && my_strchr(delim, *start))
	{
		start++;
	}

	if (*start == '\0')
	{
		last_str = NULL;
		return (NULL);
	}

	end = start + 1;
	while (*end && !my_strchr(delim, *end))
	{
		end++;
	}

	*end = '\0';
	last_str = end + 1;
	return (start);
}

/**
 * my_setenv - add or modify an environment variable
 * @name: the name of the environment variable to set
 * @value: the value to set the environment variable to
 * @overwrite: a flag indicating whether to overwrite
 * the variable if it already exists
 *
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	size_t i, max_environ = 100;
	int namelen = my_strlen(name), valuelen = my_strlen(value);
	size_t varlen = namelen + valuelen + 2;
	char *new_var = malloc(varlen);

	if (!name || !*name || my_strchr(name, '=') || !value || !environ)
		return (-1);

	if (!new_var)
		return (-1);

	my_strcpy(new_var, name);
	my_strcat(new_var, "=");
	my_strcat(new_var, value);

	for (i = 0; environ[i]; i++)
	{
		if (my_strncmp(environ[i], name, namelen) == 0 &&
				environ[i][namelen] == '=')
		{
			if (overwrite)
				my_strncpy(environ[i], new_var, varlen);

			free(new_var);
			return (0);
		}
	}

	if (i >= max_environ)
	{
		free(new_var);
		return (-1);
	}

	environ[i] = new_var;
	environ[i + 1] = NULL;

	return (0);
}


/**
 * my_unsetenv - remove an environment variable
 * @name: the name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */
int my_unsetenv(const char *name)
{
	int i, j, name_len;

	if (!name || !*name || my_strchr(name, '=') || !environ)
		return (0);
	name_len = my_strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, name_len) == 0 &&
				environ[i][name_len] == '=')
		{
			for (j = i; environ[j + 1] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;
			return (0);
		}
	}
	return (0);
}


/**
 * my_atoi - Converts a string to integer
 * @s: string to be converted
 *
 * Description: String converter
 *
 * Return: Converted string
 */
int my_atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}


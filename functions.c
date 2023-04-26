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
		return (char *)str;
	} 

	else 
	{
		return NULL;
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
 * setenv - add or modify an environment variable
 * @name: the name of the environment variable to set
 * @value: the value to set the environment variable to
 * @overwrite: a flag indicating whether to overwrite the variable if it already exists
 *
 * Return: 0 on success, -1 on failure
 */

int my_setenv(const char *name, const char *value, int overwrite)
{
	char *new_var;
	size_t new_var_len;
	int i, name_len, value_len;

	if (name == NULL || *name == '\0' || my_strchr(name, '=') != NULL || value == NULL || environ == NULL)
	{
		return (-1);
	}

	name_len = strlen(name);
	value_len = strlen(value);
	new_var_len = name_len + value_len + 2;

	new_var = (char*)malloc(new_var_len);

	if (new_var == NULL)
	{
		return (-1);
	}

	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			if (overwrite == 0)
			{
				free(new_var);
				return (0);
			}
			else
			{
				strncpy(environ[i], new_var, new_var_len);
				free(new_var);
				return (0);
			}
		}
	}

	if (environ[i] == NULL)
	{
		environ[i] = new_var;
		environ[i+1] = NULL;
		return (0);
	}
	else
	{
		free(new_var);
		return (-1);
	}
}

/**
 * unsetenv - remove an environment variable
 * @name: the name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */

int my_unsetenv(const char *name)
{
	if (name == NULL || *name == '\0' || my_strchr(name, '=') != NULL || environ == NULL)
	{
		return 0;
	}

	int i, j, name_len;
	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			for (j = i; environ[j+1] != NULL; j++)
			{
				environ[j] = environ[j+1];
			}
			environ[j] = NULL;
			return 0;
		}
	}
	return 0;
}


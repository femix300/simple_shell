#include "main.h"

/**
 * my_strchr - locate character in string
 *
 * @str: pointer to the string to be searched
 * @ch: character to be located
 *
 * Description: How to locate a character in a string
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
 * Description: Spliting strings into tokens
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
 * Description: Modifying environmental variables
 *
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	char *new_var;
	size_t new_var_len;
	int i, nam_len, valu_len;

	if (name == NULL || *name == '\0' || value == NULL)
		return (-1);
	if (my_strchr(name, '=') != NULL || environ == NULL)
		return (-1);
	nam_len = my_strileng(name);
	valu_len = my_strileng(value);
	new_var_len = nam_len + valu_len + 2;
	new_var = (char *)malloc(new_var_len);
	if (new_var == NULL)
		return (-1);
	my_st(new_var, name, "=", value);

	i = find_env_index(name);
	if (i >= 0)
	{
		if (overwrite == 0)
		{
			free(new_var);
			return (0);
		}
		else
		{
			my_strncpy(environ[i], new_var, new_var_len);
			free(new_var);
			return (0);
		}
	}
	else
	{
		return (insert_new_env(new_var));
	}
}

/**
 * my_unsetenv - remove an environment variable
 * @name: the name of the environment variable to remove
 * Description: A function that removes an environmental variable
 * Return: 0 on success, -1 on failure
 *
 */

int my_unsetenv(const char *name)
{
	int i, j, nam_len;

	if (name == NULL || *name == '\0')
		return (0);

	if (my_strchr(name, '=') != NULL || environ == NULL)
		return (0);

	nam_len = my_strileng(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, nam_len) == 0 && environ[i][nam_len] == '=')
		{
			for (j = i; environ[j + 1] != NULL; j++)
				environ[j] = environ[j + 1];
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

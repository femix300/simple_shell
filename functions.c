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

	name_len = my_strileng(name);
	value_len = my_strileng(value);
	new_var_len = name_len + value_len + 2;

	new_var = (char*)malloc(new_var_len);

	if (new_var == NULL)
	{
		return (-1);
	}

	my_strcpy(new_var, name);
	my_strcat(new_var, "=");
	my_strcat(new_var, value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
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
	int i, j, name_len;

	if (name == NULL || *name == '\0' || my_strchr(name, '=') != NULL || environ == NULL)
	{
		return 0;
	}

	name_len = my_strileng(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
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


/**
 * my_atoi - Converts a string to integer
 * @s: string to be converted
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

/**
 * my_strcpy - Copies a string
 *
 * @dest: Destination
 *
 * @src: source string
 *
 * Return: pointer to dest
 */
char *my_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * my_strileng - String length
 *
 * @s: String
 *
 * Return: String length
 */
int my_strileng(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * my_strncpy - Copies a string at maximum bytes
 *
 * @desti: Destination
 *
 * @src: Source
 *
 * @b: maximum number of bytes to copy
 *
 * Return: pointer to the resulting string dest
 */
char *my_strncpy(char *desti, const char *src, int b)
{
	int j;

	for (j = 0; j < b && src[j] != '\0'; j++)
		desti[j] = src[j];

	for ( ; j < b; j++)
		desti[j] = '\0';

	return (desti);
}

/**
 * my_strcmp - Compares two strings
 *
 * @fs1: First string
 *
 * @ss2: Second string
 *
 * Return: integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int my_strcmp(char *fs1, char *ss2)
{
	int j;

	for (j = 0; fs1[j] != '\0' && ss2[j] != '\0'; j++)
	{
		if (fs1[j] != ss2[j])
			return (fs1[j] - ss2[j]);
	}

	if (fs1[j] != '\0' || ss2[j] != '\0')
		return (fs1[j] - ss2[j]);

	return (0);
}
/*
 *my_strcat - concatenates two strings from src to dest
 * @dest: destination string
 * @src: source string
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
 *
 * Return: pointer to the new block of memory
 */
void *my_realloc(void *ptr, unsigned int new_size)
{
    void *new_ptr;
    size_t old_size = ptr ? sizeof(*ptr) : 0;

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        return NULL;
    }

    if (ptr != NULL)
    {
        my_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
        free(ptr);
    }

    return new_ptr;
}
/**
 *my_memcpy - a function that copies memory area
 *@dest: memory where is stored
 *@src: memory where is copied
 *@n: number of bytes
 *
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
				return -1;
			}
			else
			{
				return 1;
			}
		}
		if (s1[i] == '\0')
		{
			return 0;
		}
	}
	return 0;
}
/**
 * my_getenv - It returns the value environment variable
 *
 * @name: Environment name
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
			return var;
		}
	}
	return NULL;
}

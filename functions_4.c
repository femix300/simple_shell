#include "main.h"

/**
 * find_env_index - A function that finds the new index
 *
 * @name: Index name
 *
 * Return: 0
 */
int find_env_index(const char *name)
{
	int i, nam_len;

	nam_len = my_strileng(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, nam_len) == 0 && environ[i][nam_len] == '=')
		{
			return (i);
		}
	}
	return (-1);
}
/**
 * insert_new_env - A function that inserts a new variable
 *
 * @new_var: Variable name
 *
 * Return: 0
 */
int insert_new_env(char *new_var)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)

	environ[i] = new_var;
	environ[i + 1] = NULL;
	return (0);
}


#include "main.h"
/**
 * error_1 - Allocation error
 *
 * @buff: Check buffer
 * Return: -1 on eror.
 */
int error_1(char *buff)
{
	if (!buff)
	{ perror("hsh: allocation error\n");
		return (-1);
	}
	else
		return (0);
}

/**
 * error_2 -  Allocation error
 * @rea_path: Path destination
 * @buff: Check buffer
 * Return: -1 (Error).
 */
int error_2(char *buff, char *rea_path)
{
	if (!buff)
	{ free(rea_path);
		perror("hsh: allocation error\n");
		return (-1);
	}
	return (0);
}


/**
 * my_chpath - handles the path in a shell
 * @args: the arguments passes in
 * @flg: The flag command
 * Description: A functions that handles shell path
 * Return: the path as a sommand
 */
char **my_chpath(char **args, int *flg)
{
	char *path, *rea_path, *path_duplicate, **token;
	int n, m;

	for (m = 0; *(args[0] + m) != '\0'; m++)
	{
		if (*(args[0] + m) == '/')
			return (args);
	}
	rea_path = malloc(sizeof(char) * 1024);
	if (error_1(rea_path) == -1)
		return (NULL);
	path = my_getenv("PATH");
	path_duplicate = malloc((my_strileng(path) + 1) * sizeof(char *));
	if (error_2(path_duplicate, rea_path) == -1)
		return (NULL);
	token = my_pathsplt(path, path_duplicate);
	if (token == NULL)
	{
		free(path_duplicate);
		return (NULL);
	}
		for (n = 0; (token + n) != NULL; n++)
		{
			my_strcpy(rea_path, *(token + n));
			if (*rea_path != '\0')
				my_strcat(rea_path, "/");
			else
				my_strcat(rea_path, "./");
			my_strcat(rea_path, args[0]);
			if (access(rea_path, X_OK) != -1)
			{
				args[0] = rea_path;
				*flg = 1;
				return (args);
			}
		}
		free(rea_path);
		free(token);
		free(path_duplicate);
		perror("hsh");
		return (NULL); }

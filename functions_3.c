#include "main.h"

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
 * my_st - copies the contents of src1, src2 and src3 to dest
 * @dest: destination string
 * @src1: source string 1
 * @src2: source string 2
 * @src3: source string 3
 *
 * Return: void
 */
void my_st(char *dest, const char *src1, const char *src2, const char *src3)
{
	while (*src1)
	{
		*dest++ = *src1++;
	}

	while (*src2)
	{
		*dest++ = *src2++;
	}

	while (*src3)
	{
		*dest++ = *src3++;
	}

	*dest = '\0';
}

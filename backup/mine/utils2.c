#include "shell.h"

/**
 * _strcpy - the function is used to sopy a string
 * @destination: pointer to the destination
 * @source: pointer to the source file
 * Return: pointer to destination file
 */
char *_strcpy(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = 0;
	return (destination);
}

/**
 * _strcat - the function is used to perform string concatenation
 * @destination: the pointer to the destination file
 * @source: the pointer to the source file
 * Return: pointer to destination file
 */
char *_strcat(char *destination, const char *source)
{
	char *ptr = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (ptr);
}

/**
 * _strdup - the function is used to duplicate a string
 * @string: the pointer to the string to be duplicated
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *string)
{
	int len = 0;
	char *ptr;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--string;
	return (ptr);
}

/**
 *_putchar - the function writes the character to the stdout
 * @c: character to be printed to te standard output
 * Return: 1 showing success and -1 for failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strspn - the function gets the length of a substring
 * @c: pointer to string input
 * @accept: substring prefix to be looked for
 * Return: the number of bytes or the length
 */
unsigned int _strspn(char *c, char *accept)
{
	unsigned int i, j;

	for (i = 0; c[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (c[i] == accept[j])
				break;
		}
		if (!accept[j])
			return (i);
	}

	return (i);
}

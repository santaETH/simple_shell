#include "shell.h"

/**
 * _strlen - the function return the length of the string passed as argument
 * @str: pointer to te string or the argument passed
 * Return: length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}

/**
 * _strcmp - the function compares two strings
 * @str1: the pointer to the first string passed as argument
 * @str2: the poinetr to the second string passed as argument
 * Return: 0 if s1 and s2 are equal, 1 for less and 2 if greater
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((int) (*str1) - (*str2));
}

/**
 * _strncmp - the string is used for string comparison
 * @str1: pointer to the first string to be compared
 * @str2: poinetr to the second string to be compared
 * @range: maximum number of length the strings are to compared
 * Return: 0 if equal, 1 if less and 2 if greater, str1 and str
 */
int _strncmp(const char *str1, const char *str2, size_t range)
{
	unsigned char i, j;

	while (range-- > 0)
	{
		i = (unsigned char) *str1++;
		j = (unsigned char) *str2++;

		if (i != j)
			return (i - j);
		if (i == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - checks if the functions passed as arguments start with haystack
 * @haystack: pointer to te string to be searched
 * @needle: pointer to the substring to find
 * Return: address of the next haystack
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - the function searches for a string in character
 * @str: pointer to the input array passed in the terminal
 * @n: character to be searched
 * Return: the first occurence of that character if found or null if not
*/

char *_strchr(char *str, char n)
{
	while (*str != '\0')
	{
		if (*str == n)
			return (str);
		str++;
	}
	if (*str == n)
		return (str);

	return (NULL);
}

#include "shell.h"

/**
 * _getenv -finds the value of an environment variable
 * @name: pointer to the name of the environment variable
 * Return: name of the environment variable
 */
char *_getenv(const char *name)
{
	char **environment;
	size_t string_len = _strlen(name);

	for (environment = environ; *environment != NULL; environment++)
	{
		if (_strncmp(*environment, name, string_len) == 0 &&
				(*environment)[string_len] == '=')
		{
			return (&(*environment)[string_len + 1]);
		}
	}

	return (NULL);
}

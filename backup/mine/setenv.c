#include "shell.h"

/**
 * setenv_command - the function sets the environment variable
 * @arguments: arguments passed as the name of the environment
 * Return: 0 showing success
 */
int setenv_command(char **arguments)
{
	char *str, *path_value;

	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		_outputerr("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	str = arguments[1];
	path_value = arguments[2];

	if (setenv(str, path_value, 1) != 0)
	{
		_outputerr("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unsetenv_command - the function unsets the environment variable
 * @arguments: pointer to the arguments passed as the environment name
 * Return: 0 showing success
 */
int unsetenv_command(char **arguments)
{
	char *str;

	if (arguments[1] == NULL)
	{
		_outputerr("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	str = arguments[1];

	if (unsetenv(str) != 0)
	{
		_outputerr("unsetenv");
	}
	return (0);
}

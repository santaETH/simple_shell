#include "shell.h"

/**
 * environment_variables - The Fun prints all the variables in the env
 * Return: null
 */

int environment_variables(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}

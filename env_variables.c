#include "shell.h"

/**
 * environment_variables - he function prints all the variables in the environ
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

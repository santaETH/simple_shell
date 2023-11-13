#include "shell.h"

/**
 * cd_implementation - changes the current working directory of the shell
 * @arguments: pointer to pointer to teh arguments passed to the terminal
 * Return: null
 */
void cd_implementation(char **arguments)
{
	char *directories = arguments[1];
	int status;

	if (directories == NULL)
	{
		directories = _getenv("HOME");
		if (directories == NULL)
		{
			_puts("cd: No main or Home directory\n");
			return;
		}
	}

	status = chdir(directories);
	if (status == -1)
	{
		perror("cd");
	}
}

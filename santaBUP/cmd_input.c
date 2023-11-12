#include "shell.h"

/**
 * main - Strating point of the program
 *
 * Return: Status
 */

int main(void)
{
	char **argv;
	char *envp[] = {NULL};

	while (1)
	{
		argv = ma_input();
		if (argv == NULL)
		{
			return (0);
		}
		
		if (argv[0][0] != '~' && argv[0][0] != '/' && argv[0][0] != '.')
			_execve(argv[0] - 5, argv, envp);
		else
			_execve(argv[0], argv, envp);
		
		free(argv[0] - 5);
		free(argv);
	}

	return (0);
}

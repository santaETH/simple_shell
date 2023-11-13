#include "shell.h"

/**
 * free_error - frees the previous memory located for error check
 * @argv: pointer to a pointer to an array of pointers passed at teh terminal
 * @arguments: pointer to a pointer to array of characters passed to terminal
 * Return: null
 */
void free_error(char **argv, char *arguments)
{
	int j;

	for (j = 0; argv[j]; j++)
		free(argv[j]);
	free(argv);
	free(arguments);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - frees memory allocated dynamically by tokenize()
 * @pointer: the poinetr to the allocated memory
 * Return: void.
 */
void free_tokens(char **pointer)
{
	int j;

	for (j = 0; pointer[j]; j++)
		free((pointer[j]));
	free(pointer);
}


/**
 * free_path - frees the variable containing the path environment
 * Return: null
 */
void free_path(void)
{
	size_t i = 0;

	if (environ != NULL)
	{
		while (environ[i] != NULL)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}

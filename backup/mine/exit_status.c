#include "shell.h"

/**
 * terminal_exit - the function to exit the terminal
 * @arguments: arguments passed by the user to the terminal
 * Return: null
 */
void terminal_exit(char **arguments)
{
	int code_state = 0;

	if (arguments[1] != NULL)
	{
		code_state = _atoi(arguments[1]);
	}
	free_tokens(arguments);
	freeing_recent_arg();
	exit(code_state);
}

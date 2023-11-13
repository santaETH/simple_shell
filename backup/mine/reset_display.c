#include "shell.h"

/**
 * reset_shell_display - clears the screen for the next user input
 * @args: pointer to pointers passed in the terminal
 * Return: 1 to continue and 0 to terminate or exit
*/
int reset_shell_display(char **args)
{
	(void)args;
	_puts("\033[2J\033[H");
	return (1);
}

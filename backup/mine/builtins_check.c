#include "shell.h"
/**
 * builtins_check - the function checks if the commands are builtin
 * @arguments:pointer to pointer to the arguments checked as arguments
 * Return: 1 if builtin and 0 otherwise
 */
int builtins_check(char **arguments)
{
	if (!arguments[0])
		return (0);
	if (!_strcmp(arguments[0], "exit"))
		terminal_exit(arguments);
	else if (!_strcmp(arguments[0], "env"))
		environment_variables();
	else if (!_strcmp(arguments[0], "setenv"))
		setenv_command(arguments);
	else if (!_strcmp(arguments[0], "unsetenv"))
		unsetenv_command(arguments);
	else if (!_strcmp(arguments[0], "help"))
		man_help();
	else if (!_strcmp(arguments[0], "cd"))
		cd_implementation(arguments);
	else if (!_strcmp(arguments[0], "clear"))
		reset_shell_display(arguments);
	else
		return (0);
	return (1);
}

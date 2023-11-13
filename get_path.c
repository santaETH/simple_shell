#include "shell.h"

/**
 * get_path_env - Returns the value of the PATH enviroment variable.
 * Return: Pointer to the value of $PATH.
 */
char *get_path_env(void)
{
	return (_getenv("PATH"));
}

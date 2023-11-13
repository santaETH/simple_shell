#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_variable - the function handles the variables $?
 * @input: the command being passed to the terminal
 * Return: null
 */
void handle_variable(char *input)
{
	pid_t child_id = getpid();
	int most_recently_exited = WEXITSTATUS(EXIT_SUCCESS);
	size_t path_length = strlen(getenv("PATH"));

	char buffer[20];
	char *var;
	char *var_status;
	char *path_var;

	var_status = "$?";
	path_var = "$PATH";

	snprintf(buffer, sizeof(buffer), "%d", child_id);

	while ((var = strstr(input, "$$")) != NULL)
	{
		memmove(var + strlen(buffer), var + 2, strlen(var + 2) + 1);
		memcpy(var, buffer, strlen(buffer));
	}

	while ((var = strstr(input, var_status)) != NULL)
	{
		memmove(var + strlen(buffer), var + strlen(var_status),
				strlen(var + strlen(var_status)) + 1);
		snprintf(var, sizeof(buffer), "%d", most_recently_exited);
	}
	
	while ((var = strstr(input, path_var)) != NULL)
	{
		memmove(var + path_length, var + strlen(path_var),
				strlen(var + strlen(path_var)) + 1);
		memcpy(var, getenv("PATH"), path_length);
	}
}

#include "shell.h"

static char *last_input;
/**
 * get_inputs - takes the user commands passed from the command line
 * Return: the user input declared in terminal
*/
char *get_inputs(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_length;

	do {
		terminal_prompt();
		input_length = getline(&input, &input_size, stdin);

		if (input_length == -1)
		{
			free(input);
			_puts("\n");
			return (NULL);
		}

		input[input_length - 1] = '\0';
	} while (input[0] == '\0' || isspace(input[0]));

	last_input = input;
	return (input);
}

/**
 * freeing_recent_arg - it frees up the memory for the most recent arguments
 * Return: null
 */
void freeing_recent_arg(void)
{
	free(last_input);
	last_input = NULL;
}

#include "shell.h"

/**
 * main - introduction phase of our code
 * Return: 0 if success
 */
int main(void)
{
	char *user_input;
	char **arguments;
	int code_state;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		user_input = get_inputs();
		if (!user_input || !*user_input)
			break;

		handle_variable(user_input);
		arguments = tokenize_input(user_input);
		if (!arguments || !*arguments)
		{
			free(user_input);
			free_tokens(arguments);
			continue;
		}
		code_state = prompt_execution(arguments);
		free(user_input);
		free_tokens(arguments);

		code_state = 1;
	} while (code_state);

	return (EXIT_SUCCESS);
}

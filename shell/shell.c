#include "shell.h"
/**
 * show_prompt - this is the function to our prompt
 * Return: null
 */
void show_prompt(void)
{
	printing("#ASUSSHELL$ ");
	fflush(stdout);
}
/**
 * user_input - the user input to be entered within the command line
 * @buffer: the pointer t the storage of the inputs
 * @len: maximum length of the user input
 * Return: the maximum number of characters passed by the user
 */
int user_input(char *buffer, int len)
{
	return (fgets(buffer, len, stdin) == NULL ? 0 : strlen(buffer));
}

/**
 * prompt_execution - the function that executes the prompt
 * @format: The message being passed
 * Return: 0 if success
 */
int prompt_execution(const char *format)
{
	pid_t id;
	int exit_status;

	id = fork();

	if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (id == 0)
	{
		char *args[2];

		args[0] = strdup(format);
		args[2] = NULL;

		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(id, &exit_status, 0);
		if (WIFEXITED(exit_status))
		{
			printing("Exited %d\n", WEXITSTATUS(exit_status));
		}
	}
	return (0);
}

/**
 * tokenized_input - it takes a user input string and tokenizes it
 * @user_input: serves as the function signature
 * Return: returns an array of strings (pointers to characters)
 */
char **tokenized_input(char *user_input)
{
	char **parsed_input;
	char *temp_copy;

	parsed_input = NULL;
	temp_copy = NULL;
	temp_copy = strdup(user_input);
	if (temp_copy == NULL)
	{
		fprintf(stderr, "Memory allocation terminated\n");
		exit(EXIT_FAILURE);
	}

	parsed_input = tokenization(temp_copy, "\t\r\n\a");
	free(temp_copy);

	return (parsed_input);
}

/**
 * main - it serves as the entry point to our code
 * Return: 0 if success
 */
int main(void)
{
	char input[MAXIMUM_INPUT];
	char **tokens;
	int i;

	while (1)
	{
		show_prompt();
		if (user_input(input, sizeof(input)) == 0)
		{
			printing("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		tokens = tokenized_input(input);

		if (tokens != NULL && tokens[0] != NULL)
		{
			if (prompt_execution(input) == -1)
			{
				fprintf(stderr, "command not found: %s\n", tokens[0]);
			}
		}

		if (tokens)
		{
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
		}
	}
	return (0);
}

#include "shell.h"

/**
 * tokenization - the function is used to split strings into tokens using delim
 * @string: the string to be tokenized.
 * @delimiter: pointer that is set for splittint the string into tokens
 * Return: pointer to an array of tokens
 */
char **tokenization(char *string, const char *delimiter)
{
	char *tokens = NULL;
	char **c = NULL;
	int i = 0;

	tokens = strtok(string, delimiter);
	while (tokens)
	{
		c = realloc(c, sizeof(char *) * (i + 1));
		if (c == NULL)
			return (NULL);

		c[i] = malloc(_strlen(tokens) + 1);
		if (!(c[i]))
			return (NULL);

		_strcpy(c[i], tokens);
		tokens = strtok(NULL, delimiter);
		i++;
	}
	c = realloc(c, (i + 1) * sizeof(char *));
	if (!c)
		return (NULL);

	c[i] = NULL;
	return (c);
}

/**
 * input_tokenization - splits a user input string into tokens with tokenize().
 * @user_command: the user input string to be tokenized
 * Return: array of pinter to the tokens
 */
char **input_tokenization(char *user_command)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(user_command);
	if (tmp == NULL)
	{
		_puts("Error while allocating memory\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenization(tmp, "  \t\r\n\a");
	free(tmp);

	return (tokens);
}

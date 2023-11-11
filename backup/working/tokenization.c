#include "shell.h"

/**
 * tokenization - Tokenize a string into an array of strings.
 * @src: The source string to be tokenized.
 * @delimiter: The delimiter string for tokenization.
 *
 * Return: An array of strings (tokens) or NULL on failure.
 */
char **tokenization(char *src, const char *delimiter)
{
	char *token;
	char **tokens = NULL;
	size_t token_count = 0;

	if (!src || !delimiter)
		return (NULL);
	token = strtok(src, delimiter);
	while (token)
	{
		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		if (!tokens)
		{
			free_tokens(tokens);
			return (NULL);
		}

		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free_tokens(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		token_count++;
	}
	tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
	if (!tokens)
	{
		free_tokens(tokens);
		return (NULL);
	}
	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * split_string - Split a string into an array of strings.
 * @str: The input string to be split.
 * @delimiter: The delimiter string for splitting.
 * @argc: Pointer to store the number of tokens.
 *
 * Return: An array of strings (tokens) or NULL on failure.
 */
char **split_string(char *str, const char *delimiter, int *argc)
{
	char **tokens = tokenization(str, delimiter);

	if (!tokens)
		return (NULL);
	*argc = 0;
	while (tokens[*argc])
		(*argc)++;
	return (tokens);
}

/**
 * free_tokens - Free the memory allocated for an array of strings.
 * @tokens: The array of strings to be freed.
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;
	for (i = 0; tokens[i]; ++i)
		free(tokens[i]);
	free(tokens);
}

#include "shell.h"
/**
 * tokenization - the function to tokenization
 * @src: the pointer to the source string to be tokenized
 * @delimeter: pointer to the string that defines the delimeter character
 * Return: returns a pointer to an array of pointers to characters (strings)
 */
char **tokenization(char *src, const char *delimeter)
{
	char *current_token;
	char **tokenized_string;
	int i;

	current_token = NULL;
	tokenized_string = NULL;
	i = 0;

	current_token = strtok(src, delimeter);

	while (current_token)
	{
		tokenized_string = realloc(tokenized_string, sizeof(char *) * (i + 1));
		if (tokenized_string == NULL)
			return (NULL);

		tokenized_string[i] = malloc(strlen(current_token) + 1);
		if (!tokenized_string[i])
			return (NULL);

		strcpy(tokenized_string[i], current_token);
		current_token = strtok(NULL, delimeter);
		i++;
	}

	tokenized_string = realloc(tokenized_string, (i + 1) * sizeof(char *));
	if (!tokenized_string)
		return (NULL);

	tokenized_string[i] = NULL;

	return (tokenized_string);
}

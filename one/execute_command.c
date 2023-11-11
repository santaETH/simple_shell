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
        tokens = _realloc(tokens, token_count, sizeof(char *));
        if (!tokens)
        {
            free_tokens(tokens);
            return (NULL);
        }

        tokens[token_count] = _strdup(token);
        if (!tokens[token_count])
        {
            free_tokens(tokens);
            return (NULL);
        }

        token = strtok(NULL, delimiter);
        token_count++;
    }

    tokens = _realloc(tokens, token_count, sizeof(char *));
    if (!tokens)
    {
        free_tokens(tokens);
        return (NULL);
    }

    tokens[token_count] = NULL;
    return (tokens);
}


#include "shell.h"
#include <stddef.h>

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
    extern char **environ;

    char **env;
    size_t name_len = _strlen(name);

    for (env = environ; *env != NULL; env++)
    {
        if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            return (&(*env)[name_len + 1]);
        }
    }

    return (NULL);
}

/**
 * get_path - Get the PATH variable from the environment
 *
 * Return: Value of the PATH variable, or NULL if it doesn't exist
 */
char *get_path(void)
{
    return _getenv("PATH");
}

/**
 * execute_command - Execute a command using execve and handle PATH
 * @command: Command to be executed
 * @arguments: Arguments for the command
 *
 * Return: 0 for success, -1 for failure
 */
int execute_command(char *command, char **arguments)
{
    char *path = get_path();
    char **path_tokens, *full_path;
    int i;

    if (path == NULL)
    {
        perror("Error: PATH variable not found");
        return -1;
    }

    path_tokens = tokenization(path, ":");
    if (path_tokens == NULL)
    {
        perror("Error: Failed to tokenize PATH");
        return -1;
    }

    for (i = 0; path_tokens[i] != NULL; i++)
    {
        full_path = _strcat(path_tokens[i], "/");
        full_path = _strcat(full_path, command);

        if (check_file_status(full_path, NULL))
        {
            execve(full_path, arguments, environ);
            perror("Error(execve)");
        }

        free(full_path);
    }

    perror("Error: Command not found");
    return -1;
}


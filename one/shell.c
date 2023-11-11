#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char **args;
    int status;

    while (1)
    {
        printing("#cisfun$ ");
        characters = getline(&buffer, &bufsize, stdin);

        if (characters == EOF)
        {
            printing("\n");
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        buffer[characters - 1] = '\0';
        args = tokenization(buffer, " ");

        if (args == NULL)
        {
            perror("tokenization");
            free(buffer);
            exit(EXIT_FAILURE);
        }

        if (args[0] == NULL)
        {
            free(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free(buffer);
            free(args);
            exit(EXIT_SUCCESS);
        }

        if (execute_command(args, &status) == -1)
        {
            perror("execute_command");
            free(buffer);
            free(args);
            exit(EXIT_FAILURE);
        }

        free(args);
    }
    return (0);
}


#include "shell.h"

/**
 * exit_sh - The function exits from the shell.
 */

void exit_sh(void)
{
	printf("exit to the shell\n");
	exit(0);
}

/**
 * main - The main func of shell prog.
 *
 * Return: Always 0
 */
int main(void)
{
	char user_input[256];
	pid_t pid;
	char *args[2];

	while (1)
	{
		printf("ExitShell> ");
		fgets(user_input, sizeof(user_input), stdin);
		if (user_input[strlen(user_input) - 1] == '\n')
		{
			user_input[strlen(user_input) - 1] ='\0';
		}

		if (strcmp(user_input, "exit") == 0)
		{
			exit_sh();
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			args[0] = user_input;
			args[1] = NULL;

			if (execvp(user_input, args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
	return (0);
}

#include "shell.h"
#include <stdbool.h>
#include <unistd.h>
#include <string.h>


int _execute(char *arguments, struct stat *statbuf, char **envp);
bool check_file_status(char *pathname, struct stat *statbuf);
char **split_string(char *str, const char *delim, int *argc);

void custom_print(const char *str)
{
	size_t length = 0;
	const char *ptr = str;

	while (*ptr++ != '\0')
		length++;

	write(STDOUT_FILENO, str, strlen(str));
}

int main(void)
{
	char **env = NULL;
	char *buffer = NULL, *prompt = "$ ";
	size_t buffer_size = 0;
	ssize_t bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat statbuf;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		write(STDOUT_FILENO, prompt, 2);

		bytes = getline(&buffer, &buffer_size, stdin);
		if (bytes == -1)
		{
			perror("Error(getline)");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (buffer[bytes - 1] == '\n')
			buffer[bytes - 1] = '\0';

		wpid = fork();

		if (wpid == -1)
		{
			perror("Error(fork)");
			exit(EXIT_FAILURE);
		}

		if (wpid == 0)
			_execute(buffer, &statbuf, env);
		if (waitpid(wpid, &wstatus, 0) == -1)
		{
			perror("Error(wait)");
			exit(EXIT_FAILURE);
		}
	}
	free(buffer);
	return (0);
}

int _execute(char *arguments, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;

	argv = split_string(arguments, " ", &argc);

	if (!check_file_status(argv[0], statbuf))
	{
		perror("Error(file status)");
		exit(EXIT_FAILURE);
	}
	execve(argv[0], argv, envp);
	perror("Error(execve)");
	exit(EXIT_FAILURE);
}

bool check_file_status(char *pathname, struct stat *statbuf)
{
	int stat_return = stat(pathname, statbuf);
	if (stat_return == 0)
		return (true);
	return (false);
}

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		custom_print("Error");
		exit(EXIT_FAILURE);
	}
}

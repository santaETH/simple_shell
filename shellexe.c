#include "shell.h"

/**
 * _execve - new process setting up for a single command
 * @pathname: path to a bin or executable file and cmd
 * @argv: command line arguments to the new executable
 * @envp: enviroment variables
 *
 * Description: create a new proc, and parent
 */
void _execve(const char *pathname, char *const argv[], char *const envp[])
{
	pid_t pid;
	int status, ret;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(98);
	}
	else if (pid == 0)
	{
		ret = execve(pathname, argv, envp);
		if (ret == -1)
		{
			perror("sshell");
			exit(98);
		}
	}
	else
	{
		wait(&status);
	}
}

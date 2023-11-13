#include "shell.h"

/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t child_id;
	int code_state = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (code_state);
	if (check_for_builtin(argv))
		return (code_state);

	child_id = fork();
	if (child_id < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (child_id == -1)
		perror(argv[0]), free_tokens(argv), freeing_recent_args();
	if (child_id == 0)
	{
		envp[0] = get_path();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = find_in_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(child_id, &code_state, WUNTRACED);
		} while (!WIFEXITED(code_state) && !WIFSIGNALED(code_state));
	}
	return (code_state);
}

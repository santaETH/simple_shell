#include "shell.h"

/**
 * prompt_execute - serves to execute the user commands with arguments
 * @argv: argument vector representing arrays of argumenst passed to commandlin
 * Return: The status of our code, the user input
 */
int prompt_execution(char **argv)
{
	pid_t child_id;
	int code_state = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (code_state);
	if (builtins_check(argv))
		return (code_state);

	child_id = fork();
	if (child_id < 0)
	{
		_outputerr("fork");
		return (1);
	}
	if (child_id == -1)
		perror(argv[0]), free_tokens(argv), freeing_recent_arg();
	if (child_id == 0)
	{
		envp[0] = get_path_env();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = locate_command(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), free_tokens(argv), freeing_recent_arg();
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

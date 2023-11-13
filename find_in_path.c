#include "shell.h"

/**
 * locate_command - searches for commad stated in the path variable, environ
 * @input: pointer to the user input or argument to be searched
 * Return: pointer to the full path of the arguments passed by the user
*/
char *locate_command(char *input)
{
	struct stat file_info;
	int stat_result, index;
	char buf[PATH_MAX_LENGTH], *path_value, *result_path, **directories;

	path_value = get_path_env();
	if (!path_value)
		return (NULL);
	directories = tokenization(path_value, PATH_SEPARATOR);
	if (!directories)
		return (NULL);
	for (index = 0; directories[index]; index++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, directories[index]);
		_strcat(buf, "/");
		_strcat(buf, input);
		stat_result = stat(buf, &file_info);
		if (stat_result == 0 && S_ISREG(file_info.st_mode)
				&& (file_info.st_mode & S_IXUSR))
		{
			free_tokens(directories);
			result_path = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!result_path)
				return (NULL);
			strcpy(result_path, buf);
			return (result_path);
		}
	}
	if (stat_result == -1)
		free_tokens(directories);
	return (NULL);
}

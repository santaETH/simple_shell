#include "shell.h"

/**
 * s_parse - show prompt and gets input as an array of char
 *
 * Return: containing all valid command line input
 */

char *s_parse(void)
{
	ssize_t nread;
	char *line;
	size_t n = 0;
	char prompt[] = "$: ";

	write(STDOUT_FILENO, prompt, 3);

	nread = _getlne(&line, &n, STDIN_FILENO);
	if (nread < 1)
	{
		return (NULL);
	}

	return (line + 5);
}

/**
 * tokenization - devide a line of words in two
 * @line: pointer to begining of line of text
 * @del: str containing all chars that should divide line
 *
 * Return: A malloced array words
 */

char **tokenization(char *line, char *del)
{
	char *token;
	int c = 0;
	char **commands = malloc(20 * sizeof(char *));

	token = _strtok(line, del);
	commands[0] = token;

	while (token != NULL)
	{
		token = _strtok(NULL, del);
		commands[++c] = token;
	}

	return (commands);
}

/**
 * ma_input - entry point to the parser
 *
 * Return: Malloced pointer to an array of words
 */

char **ma_input(void)
{
	char del[] = " \n";
	char *line = s_parse();

	if (line == NULL)
	{
		write(1, "\n", 1);
		return (NULL);
	}

	while (*line == '\n')
	{
		free(line - 5);
		line = s_parse();

		if (line == NULL)
		{
			write(1, "\n", 1);
			return (NULL);
		}
	}

	return (tokenization(line, del));
}

/**
 * _getlne - To handle wrongly specified PATH
 * @line: address of a pointer to char to store texts
 * @n: holds the number of character succesfully read
 * @fd: file descriptor
 *
 * Return: number of char seen before new line EOF
 */

ssize_t _getlne(char **line, size_t *n, int fd)
{
	ssize_t c = 0;
	char *buf = malloc(1024 * sizeof(char));

	if (buf == NULL)
		return (0);

	*n = _read(buf, fd, n);
	if (*n == 0)
	{
		free(buf);
		return (0);
	}

	*line = malloc(sizeof(char) * ((*n) + 5));
	if (*line == NULL)
	{
		free(buf);
		return (0);
	}
	line[0][0] = '/';
	line[0][1] = 'b';
	line[0][2] = 'i';
	line[0][3] = 'n';
	line[0][4] = '/';
	for (c = 0; buf[c] != '\n'; c++)
	{
		line[0][c + 5] = buf[c];
	}
	line[0][c + 5] = buf[c];
	free(buf);

	return (c + 1);
}

/**
 * _read - the getline system call
 * @buf: buffer to store the line in
 * @fd: file descriptor refer to where to read
 * @n: number of chars read
 *
 * Description: This is a recurcive func
 * handles errors EOF, CTRL_C, CTRL_D ...
 *
 * Return: number of chrs sucessfully read
 */

ssize_t _read(char *buf, int fd, size_t *n)
{
	size_t temp = 0;
	size_t again = 0;

	temp = read(fd, buf, 1024);
	*n += temp;
	if (temp == 0 && *n > 0)
	{
		buf[*n] = '\n';
		return (*n + 1);
	}

	if (temp == 0)
		return (*n);

	if (buf[(*n) - 1] != '\n')
	{
		again = read(fd, &(buf[*n]), 1024);

		if (again == 0)
		{
			buf[*n] = '\n';
			return (*n + 1);
		}

		if (buf[*n + again - 1] == '\n')
			return (*n + again);
		*n += again;

		return (_read(&(buf[*n]), fd, n));
	}
	return (*n);
}

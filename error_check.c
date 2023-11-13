#include "shell.h"

/**
 * _puts - the function is used to print the string to the stdout
 * @str: pointer to the string being prinnted to the stdout
 * Return: null
 */
void _puts(char *str)
{
	size_t size;
	ssize_t input;

	size = _strlen(str);
	input = write(STDOUT_FILENO, str, size);
	if (input == -1)
	{
		perror("write");
	}
}

/**
 * _outputerr - the function prints the error to the stdout
 * @error_message: pointer to the message to be printed to the stdout
 * Return: null
 */
void _outputerr(char *error_message)
{
	size_t size;
	ssize_t input;

	size = _strlen(error_message);
	input = write(STDERR_FILENO, error_message, size);
	if (input == -1)
	{
		perror("write");
	}
}

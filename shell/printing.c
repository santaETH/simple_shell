#include "shell.h"
/**
 * printing - our printf function that we will be using for the shell project
 * @format: The pointer to the message or text to the input
 * Return: null
 */
void printing(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vprintf(format, args);
	va_end(args);
}

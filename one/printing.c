#include "shell.h"

/**
 * printing - Custom printf function for the shell.
 * @format: Format string.
 * @...: Variadic arguments.
 *
 * Return: Void.
 */
void printing(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}


#include "shell.h"

/**
 * handle_sigint - handles the signal given which is Ctrl+d
 * @signal: value being passed
 * Return: null
 */
void handle_sigint(int signal)
{
	(void) signal;
	_putchar('\n');
	terminal_prompt();
}

/**
 * handle_sigquit - implementation for handling SIGQUIT
 * @signal: value being passed as signal interrupt
 * Return: null
 */
void handle_sigquit(int signal)
{
	(void) signal;
	_outputerr("Terminating current process (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - implementation for handling SIGSTP
 * @signal: value being passed as signal interrupt
 * Return: null
 */
void handle_sigstp(int signal)
{
	(void) signal;
	_puts("\n");
	terminal_prompt();
}

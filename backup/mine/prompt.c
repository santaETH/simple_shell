#include "shell.h"

/**
 * prompt - the prompt to be displayed to the terminal for user input
 * Return: null
 */
void terminal_prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}

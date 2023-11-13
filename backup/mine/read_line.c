#include "shell.h"

/**
 * get_line - reads or gets the user input form the terminal
 * Return: null
*/
void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos, size;
	char *new_string = NULL;
	char initial_char;
	int user_input_len = 0;

	while (1)
	{
		if (buf_pos >= size)
		{
			size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (size == 0)
				return (new_string);
			else if (size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		initial_char = buffer[buf_pos];

		buf_pos++;

		if (initial_char == '\n')
		{
			new_string = realloc(new_string, user_input_len + 1);
			new_string[user_input_len] = '\0';
			return (new_string);
		}
		else
		{
			new_string = realloc(new_string, user_input_len + 1);
			new_string[user_input_len] = initial_char;
			user_input_len++;
		}
	}
}

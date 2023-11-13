#include "shell.h"

/**
 * _atoi - the funcntioon  performce string conversion to integer
 * @s: the pointer to the string to be converted
 * Return: value of the conversion
 */
int _atoi(const char *s)
{
	int i, sign;
	unsigned int n;

	i = 0;
	sign = 1;
	n = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			n = (n * 10) + (s[i] - '0');
		else
			break;
		i++;
	}
	return (n * sign);
}

/**
 **_memset - the function fills the memory with a constent byte
 *@a: pointer to the memory area
 *@b: byte to fill *s with
 *@n: amount of bytes to be filled
 *Return: pointer to the memory area a
 */
char *_memset(char *a, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		a[i] = b;
	return (a);
}

/**
 * _memcpy - this function copies memory area
 * @destination: the destination file where the contents will be copied to
 * @source: the source file whose contents are to be copied
 * @n: number or size of bytes to be copied
 * Return: 0 to show success
*/

char *_memcpy(char *destination, char *source, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		destination[i] = source[i];
	return (destination);
}

/**
 * _realloc - function that does memory reallocation
 * @init: pointer to the initial memory block
 * @old_buffer: initial memory block containing the size
 * @new_buffer: final memory block containing the size
 * Return: pointer to the iterative
 */
void *_realloc(void *init, unsigned int old_buffer, unsigned int new_buffer)
{
	char *c;

	if (!init)
		return (malloc(new_buffer));
	if (!new_buffer)
		return (free(init), NULL);
	if (new_buffer == old_buffer)
		return (init);

	c = malloc(new_buffer);
	if (!c)
		return (NULL);

	old_buffer = old_buffer < new_buffer ? old_buffer : new_buffer;
	while (old_buffer--)
		c[old_buffer] = ((char *)init)[old_buffer];
	free(init);
	return (c);
}

/**
 * _calloc - the function allocates a memory using malloc to an array
 * @size: size of array
 * @len: capacity length of each item
 * Return: pointer with new allocated memory
*/

void *_calloc(unsigned int size, unsigned int len)
{
	char *c;

	if (size == 0 || len == 0)
		return (NULL);
	c = malloc(size * len);
	if (c == NULL)
		return (NULL);

	_memset(c, 0, size * len);

	return (c);
}

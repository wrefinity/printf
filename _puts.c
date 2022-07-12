#include "main.h"

/**
 * _puts - prints string
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *len_id = str;

	while (*str)
		_putchar(*str++);
	return (str - len_id);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char arr[BUFFER_LIMIT];

	if (c == BUFFER_FLUSH || i >= BUFFER_LIMIT)
	{
		write(1, arr, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		arr[i++] = c;
	return (1);
}

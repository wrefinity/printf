#include "main.h"

/**
 * print_string - print a string
 * @args: defines the receivable list of arguments
 * Return: the number of characteres of the string
 */
int print_string(va_list args)
{
	int c;
	char *str;

	str = (va_arg(args, char *));
	if (str == 0)
		str = "(null)";
	for (int c = 0; str[c] != 0; c++)
		_putchar(str[c]);
	return (c);
}

/**
 * print_char - print a char else nothing
 * @args: defines the receivable list of arguments
 * Return: 1 if it is a char, 0 otherwise
 */
int print_char(va_list args)
{
	char c;

	c = (va_arg(args, int));
	_putchar(c);
	return (1);
}

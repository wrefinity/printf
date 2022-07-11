#include "main.h"

/**
 * get_range_checker - print \x0A, when out of range
 * @args: arguments passed to function
 * Return: length of character printed
 */
int get_range_checker(va_list list)
{
	int x, counter = 0;
	char *data;

	data = va_arg(list, char *);
	for (x = 0; data[x] != '\0'; x++)
	{
		if ((data[x] > 0 && data[x] < 32) || data[x] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar('0');
			_putchar('A');
			counter += 4;
		}
		else
		{
			_putchar(data[x]);
			counter++;
		}
	}
	return (counter);
}

/**
 * get_reverse_str - function that reverses a string
 * @args: arguments passed to function
 * Return: length of character printed
 */
int get_reverse_str(va_list args)
{
	char *elements;
	int x, y = 0, counter = 0;

	elements = va_arg(args, char *);
	for (x = 0; elements[x] != 0; x++)
		counter++;

	for (y = x - 1; y >= 0; y--)
		_putchar(elements[y]);

	return (counter);
}
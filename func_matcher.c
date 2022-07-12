#include "main.h"
/**
 * get_matcher - matches a format with a function
 * @fmt: defines the charcter string
 * @args: defines the arguments to the function
 * @p_format: defines the functions for printing
 * Return: an indicator integer
 */


int get_matcher(const char *fmt, va_list args, p_fmt p_format[])
{
	int counter = 0, x, y, n = 0;

		if (fmt == NULL)
		return (-1);

	for (x = 0; fmt && fmt[x] != 0; x++)
	{
		if (fmt[x] != "%")
	{
		_putchar(fmt[x]);
		counter++;
		}
		else
		{
	for (y = 0; p_format[y].symbol; y++)
	{
		if (p_format[y].symbol[0] == fmt[x + 1])
		{
			n = p_format[y].print(args);
			counter += n;
			x++;
			break;
		}

	}
		if (p_format[y].symbol == NULL && fmt[x + 1] != ' ')
		{
			if (fmt[x + 1] != 0)
			{
				_putchar(fmt[x]);
				_putchar(fmt[x + 1]);
				counter += 2;
				x++;
			}
			else
				return (-1);
		}
	}
}
	return (counter);
}

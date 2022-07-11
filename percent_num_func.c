#include "main.h"


/**
 * func_percent - print the percent
 * @args: defines recieved by func_percent
 * Return: 1 
 */
int print_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * print_num - Prints an integer
 * @args: defines recieved by func_num
 * Return: number of digit
 */
int print_num(va_list args)
{
	unsigned int m;
	int i = 0, k = 0, n = 0, tag = 0;

	n = va_arg(args, int);
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n < 0)
		{
			n = -n;
			_putchar('-');
			tag++;
		}
		m = n;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = n;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			tag++;
			k--;
			m = n;
		}
		_putchar(m % 10 + '0');
		tag++;
	}
	else
	{
		return (-1);
	}
	return (tag);
}


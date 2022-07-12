#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: length of character printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int count = 0;

	while (start <= stop)
	{
		if (start != except)
			count += _putchar(*start);
		start++;
	}
	return (count);
}

/**
 * print_rev - reverse printer
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_rev(va_list list, params_t *params)
{
	(void)params;
	int x, count = 0;
	char *str = va_arg(list, char *);

	if (str)
	{
		for (x = 0; *str; str++)
			x++;
		str--;
		for (; x > 0; x--, str--)
			count += _putchar(*str);
	}
	return (count);
}

/**
 * print_rot13 - prints string in rot13
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_rot13(va_list list, params_t *params)
{
	(void)params;
	int i = 0, x = 0, count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *arg = va_arg(list, char *);
	
	while (arg[i])
	{
		if ((arg[i] >= 'A' && arg[i] <= 'Z')
		    || (arg[i] >= 'a' && arg[i] <= 'z'))
		{
			x = arg[i] - 65;
			count += _putchar(arr[x]);
		}
		else
			count += _putchar(arg[i]);
		i++;
	}
	return (count);
}
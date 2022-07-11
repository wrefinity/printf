#include "main.h"
/**
 * func_unsig_int - convert a number to unsigned integer
 * @args: arguments passed to func_unsig_int
 * Return: number of characters printed
 */
int print_unsig_int(va_list args)
{
	unsigned int m, num;
	int i, k, count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		_putchar(num + '0');
		count++;
	}
	else if (num > UINT_MAX)
	{
		m = num - UINT_MAX - 1;
		_putchar(m + '0');
		count++;
	}
	else if (num <= UINT_MAX)
	{
		m = num;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = num;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = num;
		}
		_putchar(m % 10 + '0'), count++;
	}
	else
	{
		m = (UINT_MAX + 1) - num;
		_putchar(m + '0'), count++;
	}
	return (count);
}
/**
 * get_binary_converter - convert a number into binary number
 * @args: arguments passed to function
 * Return: number of characters printed
 */
int get_binary_converter(va_list args)
{
	int flag = 0, num = 0, base = 2;

	num = va_arg(args, unsigned int);
	return (convert_bin_oct_hex(num, base, flag));

}

/**
 * get_octal_convert - Convert a number into octal number
 * @args: arguments passed to function
 * Return: number of characters printed
 */
int get_octal_convert(va_list args)
{
	int flag = 0, num = 0, base = 8;

	num = va_arg(args, unsigned int);
	return (convert_bin_oct_hex(num, base, flag));
}

/**
 * get_hex_lower_convert - Convert a number into hexadecimal
 * lowercase
 * @args: arguments passed to function
 * Return: number of characters printed
 */
int get_hex_lower_convert(va_list args)
{
	int flag = 0, num = 0, base = 16;

	num = va_arg(args, unsigned int);
	return (convert_bin_oct_hex(num, base, flag));
}

/**
 * get_hex_upper_convert - Convert a number into hexadecimal uppercase
 * @args: arguments passed to function
 * Return: number of characters printed
 */
int get_hex_upper_convert(va_list args)
{
	int num = 0, base = 16, flag = 1;

	num = va_arg(args, unsigned int);
	return (convert_bin_oct_hex(num, base, flag));
}
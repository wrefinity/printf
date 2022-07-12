#include "main.h"

/**
 * print_hex_lower - prints hexdecimal in lowercase
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_hex_lower(va_list list, params_t *params)
{
	unsigned long num;
	int c = 0, b = 16;
	char *str;

	if (params->l_mod)
		num = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_mod)
		num = (unsigned short int)va_arg(list, unsigned int);
	else
		num = (unsigned int)va_arg(list, unsigned int);

	str = convert(num, b, CONVERT_UNSIGNED | TO_LOWERCASE, params);
	if (params->hashtag_flag && num)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_hex_upper - prints hex numbers in uppercase
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_hex_upper(va_list list, params_t *params)
{
	unsigned long num, base = 16;
	int c = 0;
	char *str;

	if (params->l_mod)
		num = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_mod)
		num = (unsigned short int)va_arg(list, unsigned int);
	else
		num = (unsigned int)va_arg(list, unsigned int);

	str = convert(num, base, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && num)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - prints unsigned number
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_binary(va_list list, params_t *params)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convert(num, 2, CONVERT_UNSIGNED, params);
	int count = 0;

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	count  += print_number(str, params);
	return (count);
}

/**
 * print_octal - prints octal numbers
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_octal(va_list list, params_t *params)
{
	unsigned long num;
	char *str;
	int c = 0, base = 8;

	if (params->l_mod)
		num = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_mod)
		num = (unsigned short int)va_arg(list, unsigned int);
	else
		num = (unsigned int)va_arg(list, unsigned int);
	str = convert(num, base, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

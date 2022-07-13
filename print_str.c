#include "main.h"

/**
 * get_precision - get precision from string
 * @p: the format string
 * @params: the parameters struct
 * @list: args pass to function
 *
 * Return: a pointer
 */
char *get_precision(char *p, params_t *params, va_list list)
{
	int x = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		x = va_arg(list, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			x = x * 10 + (*p++ - '0');
	}

	params->precision = x;
	return (p);
}

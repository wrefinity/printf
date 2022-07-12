#include "main.h"
/**
 * _printf - print a char or a string
 * @format: It's a character string
 * Return: the number of character the function is printing
 */

int _printf(const char *format, ...)
{
	int counter = 0;
		if (format == NULL)
		return (-1);

	p_fmt p_format[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_num},
		{"i", print_num},
		{"%", print_percent},
		{"b", get_binary_converter},
		{"u", print_unsig_int},
		{"o", get_octal_convert},
		{"x", get_hex_lower_convert},
		{"X", get_hex_upper_convert},
		{"S", get_range_checker},
		{"r", get_reverse_str},
		{NULL, NULL},
};

	va_list args;

	va_start(args, format);

	counter = get_matcher(format, args, p_format);

	va_end(args);
	return (counter);
}

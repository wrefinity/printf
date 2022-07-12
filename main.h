#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * struct print_fmt - define the formatter
 * @sysmbol: defines the identifier
 * @print: defines the optional function
 */

struct print_fmt
{
    char *symbol;
    int (*print)(va_list args);
};
typedef struct print_fmt p_fmt;

int _putchar(char c);
int get_matcher(const char *fmt, va_list args, p_fmt p_format[]);
int convert_bin_oct_hex(unsigned int, int, int);
int get_binary_converter(va_list);
int get_octal_convert(va_list);
int get_hex_lower_convert(va_list);
int get_hex_upper_convert(va_list);
int get_range_checker(va_list);
int get_reverse_str(va_list);

int print_unsig_int(va_list);
int print_percent(va_list);
int print_string(va_list);
int print_char(va_list);
int print_num(va_list);
int _printf(const char *format, ...);

#endif
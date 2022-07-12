#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>


/**
 * struct print_fmt - define the formatter
 * @sys: defines the identifier
 * @print: defines the optional function
 */

struct print_fmt
{
    char *symbol;
    int (*print)(va_list args);
};
typedef struct print_fmt p_fmt;

int _printf(const char *format, ...);
int _putchar(char c);
int func_string(va_list);
int func_char(va_list);
int func_percent(va_list);
int get_match_func(const char *, va_list, st_fmt st_format[]);
int func_digit(va_list);
int func_binary_convert(va_list);
int func_octal_convert(va_list);
int func_hex_Upcase_convert(va_list);
int func_hex_Lowcase_convert(va_list);
int binary_oct_hex_convert(unsigned int, int, int);
int func_unsig_int(va_list list);
int func_stringUppercase(va_list list);
int func_revstr(va_list list);
int func_rot13(va_list);

#endif

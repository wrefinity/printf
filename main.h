#ifndef MAIN_H
#define MAIN_H

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

int _putchar(char c);
int _printf(const char *fmt, ...);
int print_string(va_list args);
int print_char(va_list args);
int get_matcher(const char *fmt, va_list args, p_fmt p_format[]);


#endif
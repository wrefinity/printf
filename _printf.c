#include "main.h"

int _printf(const char *fmt, ...)
{
    int tag = 0;
    if (fmt == 0)
        return (-1);

    p_fmt p_format[] = {
		{"c", print_char},
		{"s", print_string}
    };

    va_list args;
    va_start(args, fmt);
    tag = get_matcher(fmt, args, p_format);

    va_end(args);
    return tag;
}
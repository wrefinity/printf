#include "main.h"

/**
 * _printf - prints alphanumeric
 * @format: the format string
 *
 * Return: length of character printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list list;
    char *p, *start;
    params_t params = PARAMS_INIT;

    va_start(list, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (p = (char *)format; *p; p++)
    {
        init_params(&params, list);
        if (*p != '%')
        {
            count += _putchar(*p);
            continue;
        }
        start = p;
        p++;
        while (get_flag(p, &params))
        {
            p++;
        }
        p = get_width(p, &params, list);
        p = get_precision(p, &params, list);
        if (get_modifier(p, &params))
            p++;
        if (!get_identifier(p))
            count += print_from_to(start, p,
                                 params.l_mod || params.h_mod ? p - 1 : 0);
        else
            count += get_print_func(p, list, &params);
    }
    _putchar(BUFFER_FLUSH);
    va_end(list);
    return (count);
}

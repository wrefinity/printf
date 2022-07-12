#include "main.h"

/**
 * print_char - prints character
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_char(va_list list, params_t *params)
{
    char em = ' ';
    unsigned int p = 1, counter = 0, str = va_arg(list, int);

    if (params->minus_flag)
        counter += _putchar(str);
    while (p++ < params->width)
        counter += _putchar(em);
    if (!params->minus_flag)
        counter += _putchar(str);
    return (counter);
}

/**
 * print_int - prints integer
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_int(va_list list, params_t *params)
{
    long n;
    unsigned int b = 10, f = 0;

    if (params->l_mod)
        n = va_arg(list, long);
    else if (params->h_mod)
        n = (short int)va_arg(list, int);
    else
        n = (int)va_arg(list, int);
    return (print_number(convert(n, b, f, params), params));
}

/**
 * print_string - prints string
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_string(va_list list, params_t *params)
{
    char *str = va_arg(list, char *), pad_char = ' ';
    unsigned int pad = 0, count = 0, i = 0, j;

    (void)params;
    switch ((int)(!str))
    case 1:
        str = NULL_STRING;

    j = pad = _strlen(str);
    if (params->precision < pad)
        j = pad = params->precision;

    if (params->minus_flag)
    {
        if (params->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                count += _putchar(*str++);
        else
            count += _puts(str);
    }
    while (j++ < params->width)
        count += _putchar(pad_char);
    if (!params->minus_flag)
    {
        if (params->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                count += _putchar(*str++);
        else
            count += _puts(str);
    }
    return (count);
}

/**
 * print_percent - prints string
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_percent(va_list list, params_t *params)
{
    (void)list;
    (void)params;
    return (_putchar('%'));
}

/**
 * print_range - print \\xoa
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_range(va_list list, params_t *params)
{
    int count = 0, b = 16, f = 0;
    char *str = va_arg(list, char *);
    char *hex;

    if ((int)(!str))
        return (_puts(NULL_STRING));
    for (; *str; str++)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            hex = convert(*str, b, f, params);
            if (!hex[1])
                count += _putchar('0');
            count += _puts(hex);
        }
        else
        {
            count += _putchar(*str);
        }
    }
    return (count);
}
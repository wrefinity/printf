#include "main.h"

/**
 * convert - converts to respective files
 * @num: defines the number
 * @base: defines the base
 * @flags: argument flags
 * @params: defines the paramater struct
 *
 * Return: the converted string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
    static char *array;
    (void)params;
    static char buffer[BUFFER_SIZE];
    static char hexUpper[] = "0123456789ABCDEF";
    static char hexLower[] = "0123456789abcdef";
    char tag = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        tag = '-';
    }
    array = flags & TO_LOWERCASE ? hexLower : hexUpper;
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (tag)
        *--ptr = tag;
    return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_unsigned(va_list list, params_t *params)
{
    unsigned long num;
    int base = 10;

    if (params->l_mod)
        num = (unsigned long)va_arg(list, unsigned long);
    else if (params->h_mod)
        num = (unsigned short int)va_arg(list, unsigned int);
    else
        num = (unsigned int)va_arg(list, unsigned int);
    params->unsign = 1;
    return (print_number(convert(num, base, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int print_address(va_list list, params_t *params)
{
    int base = 16;
    unsigned long int ad = va_arg(list, unsigned long int);
    char *str;

    if (!ad)
        return (_puts(NULL_STRING));

    str = convert(ad, base, CONVERT_UNSIGNED | TO_LOWERCASE, params);
    *--str = 'x';
    *--str = '0';
    return (print_number(str, params));
}
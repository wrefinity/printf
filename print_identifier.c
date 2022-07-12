#include "main.h"

/**
 * get_identifier - check for identifier
 * @s: defines the string
 *
 * Return: length of character printed
 */
int (*get_identifier(char *s))(va_list ap, params_t *params)
{
    identifier_t id[] = {
        {"c", print_char},
        {"d", print_int},
        {"i", print_int},
        {"s", print_string},
        {"%", print_percent},
        {"b", print_binary},
        {"o", print_octal},
        {"u", print_unsigned},
        {"x", print_hex_lower},
        {"X", print_hex_upper},
        {"p", print_address},
        {"S", print_range},
        {"r", print_rev},
        {"R", print_rot13},
        {NULL, NULL}};
    int x = 0;

    while (id[x].identifier)
    {
        if (*s == id[x].identifier[0])
        {
            return (id[x].print);
        }
        x++;
    }
    return (NULL);
}

/**
 * get_print_func - check identifier
 * @s: defines the string
 * @list: args pass to function
 * @params: the parameters struct
 *
 * Return: length of character printed
 */
int get_print_func(char *s, va_list list, params_t *params)
{
    int (*f)(va_list, params_t *) = get_identifier(s);

    if (f)
        return (f(list, params));
    return (0);
}

/**
 * get_flag - flag getter function
 * @s: defines the string
 * @params: the struct parameters
 *
 * Return: flag
 */
int get_flag(char *s, params_t *params)
{
    int i = 0;

    switch (*s)
    {
    case '+':
        i = params->plus_flag = 1;
        break;
    case ' ':
        i = params->space_flag = 1;
        break;
    case '#':
        i = params->hashtag_flag = 1;
        break;
    case '-':
        i = params->minus_flag = 1;
        break;
    case '0':
        i = params->zero_flag = 1;
        break;
    }
    return (i);
}

/**
 * get_modifier - check for modifier
 * @s: defines the string
 * @params: the parameters struct
 *
 * Return: valid modifier
 */
int get_modifier(char *s, params_t *params)
{
    int i = 0;

    switch (*s)
    {
    case 'h':
        i = params->h_mod = 1;
        break;
    case 'l':
        i = params->l_mod = 1;
        break;
    }
    return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: defines the string
 * @params: the parameters struct
 * @list: args pass to function
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list list)
{
    int d = 0;

    if (*s == '*')
    {
        d = va_arg(list, int);
        s++;
    }
    else
    {
        while (_isdigit(*s))
            d = d * 10 + (*s++ - '0');
    }
    params->width = d;
    return (s);
}
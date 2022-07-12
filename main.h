#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_LIMIT 1024
#define BUFFER_FLUSH -1

#define BUFFER_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define TO_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_mod: on if h_mod is specified
 * @l_mod: on if l_mod is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_mod		: 1;
	unsigned int l_mod		: 1;
} params_t;

/**
 * struct identifier - struct instance
 *
 * @identifier: identifier to check
 * @print: defines the function
 */
typedef struct identifier
{
	char *identifier;
	int (*print)(va_list, params_t *);
} identifier_t;


int _puts(char *str);
int _putchar(int c);


int print_char(va_list list, params_t *params);
int print_int(va_list list, params_t *params);
int print_string(va_list list, params_t *params);
int print_percent(va_list list, params_t *params);
int print_range(va_list list, params_t *params);


char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list list, params_t *params);
int print_address(va_list list, params_t *params);


int (*get_identifier(char *s))(va_list list, params_t *params);
int get_print_func(char *s, va_list list, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list list);


int print_hex_lower(va_list list, params_t *params);
int print_hex_upper(va_list list, params_t *params);
int print_binary(va_list list, params_t *params);
int print_octal(va_list list, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list list, params_t *params);
int print_rot13(va_list list, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t *params, va_list list);


char *get_precision(char *p, params_t *params, va_list list);
int _printf(const char *format, ...);

#endif

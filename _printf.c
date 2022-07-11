#include "main.h"

int _printf(const char *format, ...)
{
  int tag = 0;
  if (format == 0)
    return (-1);

  p_fmt p_format[] = {
      {"d", print_num},
      {"i", print_num},
      {"c", print_char},
      {"s", print_string},
      {"%", print_percent},
      {NULL, NULL},
  };

  va_list args;
  va_start(args, format);
  tag = get_matcher(format, args, p_format);

  va_end(args);
  return tag;
}
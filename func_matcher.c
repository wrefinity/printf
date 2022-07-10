#include "main.h"
/**
 * get_matcher - matches a format with a function
 * @fmt: defines the charcter string
 * @args: defines the arguments to the function
 * @p_format: defines the functions for printing
 * Return: an indicator integer
 */

int get_matcher(const char *fmt, va_list args, p_fmt p_format[])
{
    int tag = 0;
    unsigned int x, y;

    if (fmt == 0)
		return (-1);
    
    for (x = 0; fmt[x] != '\0'; x++)
    {
        if(fmt[x] != "%")
        {
            _putchar(fmt[x]);
            tag++;
        }else{
            
        }

    }


	return (tag);
}
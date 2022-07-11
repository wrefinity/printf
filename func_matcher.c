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
    int tag = 0, x, y, n;

    if (fmt == NULL)
		return (-1);
    
    for (x = 0; fmt && fmt[x] != '\0'; x++)
    {
        if(fmt[x] != "%")
        {
            _putchar(fmt[x]);
            tag++;
        }else{
            for (y = 0; p_format[y].symbol && p_format[y].symbol[0] == fmt[x + 1]; y++)
			{
                n = p_format[y].print(args);
                tag += n;
                x++;
                break;
			}
			if (p_format[y].symbol == NULL && fmt[x + 1] != ' ')
			{
				if (fmt[x + 1] != 0)
				{
					_putchar(fmt[x]);
                    tag++;
					_putchar(fmt[x + 1]);
					tag++;
					x++;
				}
				else
					return (-1);
			}
        }

    }


	return (tag);
}
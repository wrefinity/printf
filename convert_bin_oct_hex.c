#include "main.h"
/**
 * convert_bin_oct_hex - convert num to binary, octal or hexadecimal
 * @num: number to convert
 * @base: base divider to binary 2; octal 8; hexadecima 16.
 * Return: number of characters
 */	
int convert_bin_oct_hex(unsigned int num, int base, int tag)
{
	int x = 1000, y = 0;
	static char hexUpper[] = "0123456789ABCDEF";
	static char hexLower[] = "0123456789abcdef";
	char array[1001];
	char *ptr;

	ptr = &array[1000];
	*ptr = '\0';

	do {
		if (tag != 0)
			*--ptr = hexUpper[num % base];
		else
			*--ptr = hexLower[num % base];
		num /= base;
		x--;
	} while (num != 0);

	for (y = x; array[y] != 0; y++)
	{
		_putchar(array[y]);
	}
	return(1000 - x);
}
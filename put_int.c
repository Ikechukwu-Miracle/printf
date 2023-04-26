#include "main.h"
/**
 * put_int - Prints integer to stdout
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int put_int(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	int x = BSIZE - 2;
	int negative = 0;
	long int n = va_arg(options, long int);
	unsigned long int number;

	n = con_size_num(n, size);

	if (n == 0)
		buff[x--] = '0';

	buff[BSIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (number > 0)
	{
		buff[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (put_number(negative, x, buff, flags, width, precision, size));
}

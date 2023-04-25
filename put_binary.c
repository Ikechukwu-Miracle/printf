#include "main.h"

/**
 * put_binary - Prints binary equivalent of number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int put_binary(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, x, sum;
	unsigned int g[32];
	int r_val;
	char z;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(options, unsigned int);
	b = 2147483648;
	g[0] = a / b;
	for (x = 1; x < 32; x++)
	{
		b /= 2;
		g[x] = (a / b) % 2;
	}
	for (x = 0, sum = 0, r_val = 0; x < 32; x++)
	{
		sum += g[x];
		if (sum || x == 31)
		{
			z = '0' + g[x];

			_putchar(z);
			r_val++;
		}
	}
	return (r_val);
}

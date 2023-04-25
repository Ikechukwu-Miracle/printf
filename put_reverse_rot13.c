#include "main.h"
/**
 * put_reverse - Prints reverse string.
 * @options: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int put_reverse(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	char *s;
	int x, r_val = 0;
	char z;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(options, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		z = str[x];

		_putchar(z);
		r_val++;
	}
	return (r_val);
}

/**
 * put_rot13 - Print a string in rot13.
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int put_rot13(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	char m;
	char *s;
	unsigned int x, y;
	int r_val = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(options, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (x = 0; s[x]; x++)
	{
		for (y = 0; input[y]; y++)
		{
			if (input[y] == s[y])
			{
				m = output[y];
				_putchar(m);
				r_val++;
				break;
			}
		}
		if (!input[y])
		{
			m = str[x];
			_putchar(m);
			r_val++;
		}
	}
	return (r_val);
}
